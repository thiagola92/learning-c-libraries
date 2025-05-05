#include "laconn.h"
#include <stdio.h>
#include <windows.h>

LA_DLL void laconnect(char *ip) {
  // Fake connecting to IP
  printf("Connecting to %s\n", ip);
  Sleep(1);
  printf("Connected\n");
}