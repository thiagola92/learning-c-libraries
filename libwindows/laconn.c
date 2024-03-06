#include "laconn.h"
#include <stdio.h>
#include <windows.h>

void laconnect(char *ip) {
  // Fake connecting to IP
  printf("Connecting to %s\n", ip);
  Sleep(1000);
  printf("Connected\n");
}