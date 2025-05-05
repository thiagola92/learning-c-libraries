#include "laconn.h"
#include <stdio.h>
#include <unistd.h>

void laconnect(char *ip) {
  // Fake connecting to IP
  printf("Connecting to %s\n", ip);
  sleep(1);
  printf("Connected\n");
}