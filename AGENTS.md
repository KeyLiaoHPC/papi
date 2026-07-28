# AGENTS.md — PAPI

Guidance for AI agents working in this repository.

## Project

**PAPI** (Performance Application Programming Interface) provides a stable C/Fortran API for hardware and software performance counters across CPUs, GPUs, memory, interconnects, I/O, power, and related subsystems.

| Item | Value |
|------|--------|
| Upstream | https://github.com/icl-utk-edu/papi |
| Docs / Wiki | https://github.com/icl-utk-edu/papi/wiki |
| Maintainer | ICL, University of Tennessee Knoxville |
| Contact | ptools-perfapi@icl.utk.edu |
| License | BSD-style (`LICENSE.txt`) |
| Version (tree) | 7.3.0.0 (`src/configure.in`, `PAPI_VERSION` in `src/papi.h`) |
| Language | C (primary), Fortran wrappers, some Python (libpfm4 / component helpers) |
| Build | Autotools: `src/configure` + Make |

Prefer existing component patterns over inventing new architecture. Coordinate large changes with maintainers early; submit **one PR per feature or bug fix**.

## Layout

```
papi/
├── README.md, INSTALL.txt, RELEASENOTES.txt, SECURITY.md
├── ChangeLogs/          # Historical release notes
├── doc/                 # Doxygen configs
├── man/                 # Man pages (generated / shipped)
├── .github/
│   ├── workflows/       # Per-component and framework CI
│   └── workflows_scripts/
└── src/                 # *** All build/configure work happens here ***
    ├── papi.c, papi.h   # Public API and framework
    ├── papi_internal.h, papi_vector.h
    ├── configure, configure.in, Makefile.in, Makefile.inc
    ├── components/      # Optional / default hardware & software backends
    ├── libpfm4/         # Bundled libpfm4 (CPU event decoding)
    ├── ctests/, ftests/ # Framework tests
    ├── utils/           # papi_avail, papi_native_avail, etc.
    ├── examples/, high-level/
    ├── counter_analysis_toolkit/  # CAT (separate CI path)
    └── run_tests.sh, run_tests_shlib.sh
```

Build, configure, and tests are rooted in **`src/`**, not the repository root.

## Build and test

```bash
cd src
./configure [--with-components="comp1 comp2 ..."] [other options]
make
make test          # quick: ctests/zero
make fulltest      # ./run_tests.sh (PASSED / FAILED / SKIPPED)
# or: ./run_tests.sh -v
make install       # libs/headers; also install-man, install-tests, install-all
```

Useful options:

- `./configure --help` — authoritative list
- `--with-components="cuda nvml rapl ..."` — extra components (space-separated, quoted)
- Default on Linux: **`perf_event`**, **`perf_event_uncore`**, **`sysdetect`** (do **not** pass these via `--with-components=`; that fails the build)
- Some components need their own `./configure` inside `src/components/<name>/` before the top-level build
- Shared-lib tool builds: `--with-shlib-tools` (CI uses `run_tests_shlib.sh`)

Do not regenerate `configure` unless the task requires it; committed `configure` scripts are kept for a specific autoconf version.

## Architecture (what to touch)

### Framework vs components

- **Framework** (`src/papi.c`, `papi.h`, OS glue, timers, presets): shared API, event sets, multiplexing, high-level API.
- **Components** (`src/components/<name>/`): backends that implement counter access. They plug in via a **`papi_vector_t`** named **`_<name>_vector`** (e.g. `_example_vector`).

Public surface for users is `papi.h`. Component internals use `papi_internal.h`, `papi_vector.h`, `papi_memory.h`.

### Adding or changing a component

Follow `src/components/README` and clone **`example`** (or **`template`** for front-end / vendor-dispatch layering):

1. Directory: `src/components/<lowercase_name>/`
2. Required: sources/headers + **`Rules.<name>`**
3. Export: `papi_vector_t _<name>_vector`
4. Optional configure: `configure.in` → `configure`, `Makefile.<name>.in` → `Makefile.<name>` (commit `configure`; do not commit generated Makefiles)
5. Tests: `tests/` with Makefile rule `<name>_tests`, include `components/Makefile_comp_tests`
6. CI: add `.github/workflows/<name>_component_workflow.yml` (see `.github/workflows/README.md`)

Do not modify framework code just to wire component tests; the make include path discovers them.

### Layered component design

Prefer `template`’s front-end / `vendor_dispatch` / `vendor_*` split when wrapping evolving vendor APIs (CUDA, ROCm, etc.): keep PAPI bookkeeping in the front-end; isolate vendor versions in the back-end.

## Coding conventions

Style is defined by **`src/.indent.pro`** (GNU `indent`, K&R-based). Before committing C changes:

- Tabs; indent / tab size 4
- Line length ≤ 80 (comments ≤ 79)
- Braces on `if` line; braces after function/struct definitions
- Space around parentheses for keywords; no space after function names
- Format new/changed C with: `indent -T <types as needed> file.c` using that profile

Other norms:

- Prefer existing patterns in the same component or `example`
- Use `papi_malloc` / PAPI memory helpers where components already do
- Keep `disabled_reason` strings null-terminated (`PAPI_MAX_STR_LEN`)
- Event counts are typically `long long` / 64-bit counters
- File headers: brief `@file`, author, Doxygen where nearby files use it
- Do not drive-by-refactor unrelated files, vendored trees (`libpfm4`, `atomic_ops`), or generated man/docs unless the task requires it

## Tests and utilities

| Area | Location | Notes |
|------|----------|--------|
| C framework tests | `src/ctests/` | Large suite; SKIPPED if unsupported |
| Fortran tests | `src/ftests/` | |
| Component tests | `src/components/<name>/tests/` | Built with main `make` |
| Utilities | `src/utils/` | `papi_avail`, `papi_native_avail`, `papi_component_avail`, … |
| Exclusions | `src/run_tests_exclude*.txt` | |

When changing behavior, add or update the closest existing test style rather than inventing a new harness.

## CI

Path-filtered GitHub Actions (self-hosted runners for GPU components):

| Change under | Workflow focus |
|--------------|----------------|
| `src/components/<name>/**` | `<name>_component_workflow.yml` |
| `perf_event`, `perf_event_uncore`, `sysdetect` | `default_components_workflow.yml` only |
| `src/counter_analysis_toolkit/**` | `cat_workflow.yml` |
| Broader `src/` (framework) | `papi_framework_workflow.yml` (multi-component, Spack, Clang) |

Scripts live in `.github/workflows_scripts/`. New components need a matching workflow YAML.

## Docs and release hygiene

- User install: `INSTALL.txt`
- Release narrative: `RELEASENOTES.txt` / `ChangeLogs/`
- API docs: `doc/` + Doxygen (`Doxyfile-html`, etc.)
- Security: report via GitHub advisories (`SECURITY.md`); do not discuss unfixed vulns in public PRs
- Prefer citation / project URLs already in `README.md` when documenting

## Agent do / don’t

**Do**

- Work from `src/` for configure/make/test
- Match the nearest component or `example` / `template` for new backends
- Keep PRs focused; update component README and CI when adding a component
- Run `make test` (and relevant component tests) after buildable changes when the environment allows

**Don’t**

- Pass default components (`perf_event`, `perf_event_uncore`, `sysdetect`) to `--with-components`
- Mass-reformat trees or rewrite `libpfm4` / third-party code casually
- Commit secrets, machine-local paths, or generated `Makefile.*` from component configures
- Expand scope beyond the requested change (no unrelated “cleanup” commits)
- Bypass security reporting process for vulnerabilities

## Quick reference: key files

| Purpose | Path |
|---------|------|
| Public API | `src/papi.h` |
| Framework implementation | `src/papi.c` |
| Component vtable | `src/papi_vector.h` |
| Component howto | `src/components/README` |
| Example component | `src/components/example/` |
| Layered template | `src/components/template/` |
| Indent / style | `src/.indent.pro` |
| Configure options | `src/configure --help` / `src/configure.in` |
| CI howto | `.github/workflows/README.md` |
