#include "laconn.h"
#include "lamsg.h"

int main(void) {
  laconnect("127.0.0.1");
  lasend("Hello world!");
}