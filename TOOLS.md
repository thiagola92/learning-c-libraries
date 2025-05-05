# 🧰 Essential Tools for C Object and Library Analysis
This is an answer from ChatGPT and I still intend to look at this tools.  

## 🔍 Symbol & Function Inspection
| Tool        | Description                                                                                        |
| ----------- | -------------------------------------------------------------------------------------------------- |
| `nm`        | Lists symbols in object, static, and shared libraries (`nm -C` demangles C++).                     |
| `objdump`   | Very powerful; shows disassembly, symbols, sections, headers, and more.                            |
| `readelf`   | ELF-specific version of `objdump`; good for detailed ELF structure.                                |
| `strings`   | Extracts printable strings from binaries (useful for debugging, or looking for embedded messages). |
| `gdb`       | The GNU debugger — for runtime inspection, symbol lookup, memory dumps.                            |
| `addr2line` | Maps memory addresses (from crashes or `nm`) back to file\:line.                                   |
| `gprof`     | GNU profiler; shows performance/function call data (requires special compilation).                 |
| `objcopy`   | Can extract or remove sections, symbols, etc. from object files.                                   |
| `strip`     | Removes symbols/debug info from binaries to shrink them.                                           |
| `size`      | Shows section sizes of object files or binaries (e.g., `.text`, `.data`, `.bss`).                  |

## 🧷 Dependency and Linking Analysis
| Tool        | Description                                                           |
| ----------- | --------------------------------------------------------------------- |
| `ldd`       | Lists shared library dependencies of a binary or `.so`.               |
| `ld`        | The GNU linker itself (used via `gcc`, but can be run directly).      |
| `patchelf`  | Modify RPATH, SONAME, etc. in ELF binaries.                           |
| `chrpath`   | Modify or inspect RPATH and RUNPATH of binaries.                      |
| `file`      | Quickly shows if a binary is 32/64-bit, ELF type, shared/static, etc. |
| `elfdump`   | Solaris-like tool; available on some systems (alt to `readelf`).      |
| `objdigger` | Advanced ELF inspector (not always pre-installed, niche usage).       |

## ⚙️ Build & Packaging Tools
| Tool                              | Description                                                               |
| --------------------------------- | ------------------------------------------------------------------------- |
| `ar`                              | The tool for creating and inspecting `.a` (static) archives.              |
| `ranlib`                          | Adds an index to `.a` files (usually automatic with `ar`).                |
| `pkg-config`                      | Helps detect compiler and linker flags for libraries.                     |
| `ldconfig`                        | Updates shared library cache (`/etc/ld.so.cache`).                        |
| `make`, `cmake`, `meson`, `ninja` | Build systems; useful for understanding how a binary or library is built. |
