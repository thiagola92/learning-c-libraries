# learning-c-libraries

# Linux - Static

Creating:
- `cd lib`
- `gcc -c laconn.c lamsg.c`
  - `-c`: Compile and assemble, but do not link
- `ar -r libla.a laconn.o lamsg.o`
  - `-r`: Replace existing or insert new file(s) into the archive

Testing:
- `cp libla.a ../test/lib`
- `cd ../test`
- `gcc main.c -o main -Iinclude -Llib -lla`
  - `-o <file>`: Place the output into `<file>`
  - `-I<dir>`: Add the directory `<dir>` to the head of the list of directories to be searched for header files
  - `-L<dir>`: Add directory `<dir>` to the list of directories to be searched for `-l`
  - `-l<name>`: Search lib `lib<name>.a`
- `./main`

# Linux - Dynamic

Creating:
- `cd lib`
- `gcc -c laconn.c lamsg.c`
  - `-c`: Compile and assemble, but do not link
- `gcc -shared -o libla.so *.o`

Testing:
- `cp libla.so ../test/lib`
- `cd ../test`
- `gcc main.c -o main -Iinclude -Llib -lla -Wl,-Rlib`
  - `-o <file>`: Place the output into `<file>`
  - `-I<dir>`: Add the directory `<dir>` to the head of the list of directories to be searched for header files
  - `-L<dir>`: Add directory `<dir>` to the list of directories to be searched for `-l`
  - `-l<name>`: Search lib `lib<name>.a`
  - `-Wl,<option>`: Pass `<option>` as an option to the GNU linker. If option contains commas, it is split into multiple options at the commas
    - This is optional, if not included it will search in the default locations (like `/usr/lib`)
- `./main`

# Windows - Static

Creating:
- `cd lib_windows`
- `cl /c laconn.c lamsg.c`
  - `/c`: Compile and assemble, but do not link
  - `/MT`: (default) A copy of the runtime library is included in the resulting executable
- `lib /OUT:libla.lib laconn.obj lamsg.obj`
  - `/OUT:<file>`: Place the output into `<file>`

Testing:
- `cp libla.lib ../test_windows/lib`
- `cd ../test_windows`
- `cl /Iinclude main.c lib\libla.lib`
  - Order matters
  - `/I<dir>`: Add the directory `<dir>` to the list of directories to be searched for header files
- `.\main.exe`

# Windows - Dynamic

Creating:
- `cd lib_windows`
- `cl /c /MD /DLA_EXPORT_DLL laconn.c lamsg.c`
  - `/c`: Compile and assemble, but do not link
  - `/MD`: Application/DLL will use the shared CRT DLL (msvcrt.dll or ucrtbase.dll)
  - `/D<definition>`: Define something exactly like `#define <definition>`
- `link /DLL /OUT:libla.dll laconn.obj lamsg.obj`
  - `/DLL`: Builds a `.dll`
  - `/OUT:<file>`: Place the output into `<file>`

Testing:
- `cp libla.dll ../test_windows/lib`
- `cp libla.lib ../test_windows/lib`
- `cd ../test_windows`
- `cl /c /Iinclude /DLA_IMPORT_DLL main.c`
  - `/c`: Compile and assemble, but do not link
  - `/I<dir>`: Add the directory `<dir>` to the list of directories to be searched for header files
  - `/D<definition>`: Define something exactly like `#define <definition>`
- `link /LIBPATH:lib lib\libla.lib main.obj`
  - Order matters
  - `/link <options>`: Pass one or more options to linker
	- `/DLL`: Builds a `.dll`
	- `/LIBPATH:<dir>`: Search lib in `<dir>` before the environmental library path
- `cp lib/libla.dll .`
  - Windows search for dynamic libraries in the current directory
- `.\main.exe`

(TOOD) Test: https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-170

# References

Both:
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s04.html
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s05.html

Linux:
- https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/
- https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
- https://www.youtube.com/watch?v=JbHmin2Wtmc

Windows:
- https://learn.microsoft.com/en-us/cpp/build/reference/compiler-command-line-syntax?view=msvc-170
- https://learn.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-alphabetically?view=msvc-170
- https://learn.microsoft.com/en-us/cpp/build/reference/linker-options?view=msvc-170
- https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-creation
- https://www.youtube.com/watch?v=Wt4dxDNmDA8
- https://stackoverflow.com/questions/47614835/how-to-compile-static-lib-library-for-windows-in-linux-or-macos
- https://stackoverflow.com/questions/77590683/compiling-a-dynamic-link-library-dll-on-windows-with-cl-exe-and-powershell-but
