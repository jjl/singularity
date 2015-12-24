#ifndef SINGULARITY_H
#define SINGULARITY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif 

  /**
   * May stop your compiler from optimising out some code
   * 
   * Useful to make benchmarks more reliable
   * 
   * @param void *p pointer to your obj
   */
  void singularity(volatile void *p);

  /**
   * Zeroes out the memory pointed to by *p and returns p
   * 
   * A cop-out for platforms that don't support secure keyboard input
   * 
   * @param void *p pointer to your obj
   * @param size_t size size of one item
   * @param size_t count number of items laid out contiguously in memory
   */
  void eat(volatile void *p, size_t size, size_t count);

#ifdef __cplusplus
}
#endif 

#endif // SINGULARITY_H

