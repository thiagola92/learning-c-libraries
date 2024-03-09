# learning-c-libraries

# Linux - Static
- `cd lib`
- `gcc -c laconn.c lamsg.c`
  - `-c`: Compile and assemble, but do not link
- `ar -r libla.a laconn.o lamsg.o`
  - `-r`: Replace existing or insert new file(s) into the archive
- `cp libla.a ../test/lib`
- `cd ../test`
- `gcc main.c -o main -Iinclude -Llib -lla`
  - `-o <file>`: Place the output into `<file>`
  - `-I<dir>`: Add the directory `<dir>` to the head of the list of directories to be searched for header files
  - `-L<dir>`: Add directory `<dir>` to the list of directories to be searched for `-l`
  - `-l<name>`: Search lib `lib<name>.a`
- `./main`

# Linux - Dynamic
- `cd lib`
- `gcc -c laconn.c lamsg.c`
  - `-c`: Compile and assemble, but do not link
- `gcc -shared -o libla.so *.o`
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
- `cd lib_windows`
- `cl /c laconn.c lamsg.c`
  - `/MT`: (default) A copy of the runtime library is included in the resulting executable
- `lib /OUT:libla.lib laconn.obj lamsg.obj`
- `cp libla.lib ../test_windows/lib`
- `cd ../test_windows`
- `cl /I include main.c lib\libla.lib`
  - Order matters
- `.\main.exe`

# Windows - Dynamic
- `cd lib_windows`
- `cl /c /MD /DLA_EXPORT_DLL laconn.c lamsg.c`
  - `/c`:
  - `/MD`: Application/DLL will use the shared CRT DLL (msvcrt.dll or ucrtbase.dll)
  - `/D<definition>`: Define something exactly like `#define <definition>`
- `link /DLL /OUT:libla.dll laconn.obj lamsg.obj`
  - `/DLL`:
  - `/OUT:<file>`:
- `cp libla.dll ../test_windows/lib`
- `cp libla.lib ../test_windows/lib`
- `cd ../test_windows`
- `cl /Iinclude /DLA_IMPORT_DLL main.c lib\libla.lib /link /DLL /LIBPATH:lib`
  - Order matters
  - `/I<dir>`: 
  - `/D<definition>`: Define something exactly like `#define <definition>`
  - `/link <options>`: Pass one or more options to linker
	- `/DLL`:
	- `/LIBPATH:<dir>`:
- `.\main.exe`

Test: https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-170

# References
- https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/
- https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
- https://learn.microsoft.com/en-us/cpp/build/reference/compiler-command-line-syntax?view=msvc-170
- https://learn.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-alphabetically?view=msvc-170
- https://learn.microsoft.com/en-us/cpp/build/reference/linker-options?view=msvc-170
- https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-creation
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s04.html
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s05.html
- https://www.youtube.com/watch?v=JbHmin2Wtmc
- https://www.youtube.com/watch?v=Wt4dxDNmDA8
- https://stackoverflow.com/questions/47614835/how-to-compile-static-lib-library-for-windows-in-linux-or-macos
- https://stackoverflow.com/questions/77590683/compiling-a-dynamic-link-library-dll-on-windows-with-cl-exe-and-powershell-but