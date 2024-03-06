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
  - `-Wl,<option>`: Pass `<option>` as an option to the GNU linker. If option contains commas, it is split into multiple options at the commas.  
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

# References
- https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/  
- https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html  