#include "lamsg.h"
#include <stdio.h>
#include <windows.h>

LA_DLL void lasend(char *msg) {
  // Fake sending msg
  printf("Sending '%s'\n", msg);
  Sleep(1);
  printf("Sent\n");
}