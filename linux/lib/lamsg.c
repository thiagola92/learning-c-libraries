#include "lamsg.h"
#include <stdio.h>
#include <unistd.h>

void lasend(char *msg) {
  // Fake sending msg
  printf("Sending '%s'\n", msg);
  sleep(1);
  printf("Sent\n");
}