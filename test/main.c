#include "laconn.h"
#include "lamsg.h"

int main(void) {
  connect("127.0.0.1");
  send("Hello world!");
}