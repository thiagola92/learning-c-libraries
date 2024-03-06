#include "lamsg.h"
#include <stdio.h>
#include <windows.h>

void lasend(char *msg) {
  // Fake sending msg
  printf("Sending '%s'\n", msg);
  Sleep(1000);
  printf("Sent\n");
}