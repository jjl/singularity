#include "singularity.h"
#include <string.h>

void singularity(volatile void *p) {
  (void) p;
  asm volatile("");
}

void eat(volatile void *p, size_t size, size_t count) {
  memset((void *)p, 0, size * count);
}

