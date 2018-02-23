/* Cutsom test  No requirements */

#include <stdio.h>
#include "tests/threads/tests.h" /* location of extern */

//Created externally in tests.h
void
test_custom_test (void)
{
  printf("Inside the custom test.");
  pass();
  //fail works like printf, but it also PANICS the kernel
  //fail("Failing is possible even if you pass.");
}
