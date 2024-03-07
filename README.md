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
- `./main`

# Windows - Static
- `cd lib_windows`
- `cl /c laconn.c lamsg.c`
  - `/MT`: (default) A copy of the runtime library is included in the resulting executable
- `lib /OUT:libla.lib laconn.obj lamsg.obj`
- `cp libla.lib ../test_windows/lib`
- `cd ../test_windows`
- `cl /I include main.c /link lib\libla.lib`
- `.\main.exe`

# Windows - Dynamic
- `cd lib_windows`
- `cl /DLA_EXPORT_DLL /MD /c laconn.c lamsg.c`
  - `/MD`: Application/DLL will use the shared CRT DLL (msvcrt.dll or ucrtbase.dll)
  - `/DLA_EXPORT_DLL`: Define LA_EXPORT_DLL
- `link /DLL /OUT:libla.dll laconn.obj lamsg.obj`
- `cp libla.dll ../test_windows/lib`
- `cd ../test_windows`
- `cl /DLA_IMPORT_DLL /I include main.c lib\libla.dll`
  - `/DLA_IMPORT_DLL`: Define LA_IMPORT_DLL
- `.\main.exe`

Test:
- `/Gy`: Enable function level liking
- `/Gd`: Calling convention

# References
- https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/
- https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
- https://stackoverflow.com/questions/47614835/how-to-compile-static-lib-library-for-windows-in-linux-or-macos
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s04.html
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s05.html
- https://www.youtube.com/watch?v=JbHmin2Wtmc
- https://www.youtube.com/watch?v=Wt4dxDNmDA8