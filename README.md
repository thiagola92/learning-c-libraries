# learning-c-libraries

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

# Windows - Static
- `cd libwindows`
- `cl -c laconn.c lamsg.c`
- `lib /OUT:libla.lib laconn.obj lamsg.obj`
- `cp libla.lib ../test/lib`
- `cd ../test`
- `cl /I include main.c /link lib/libla.lib`
  - Order matters
- `.\main.exe`

# References
- https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/
- https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
- https://stackoverflow.com/questions/47614835/how-to-compile-static-lib-library-for-windows-in-linux-or-macos
- https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s04.html