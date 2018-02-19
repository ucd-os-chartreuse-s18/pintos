/* Cutsom test  Only requirement is that it not crash.
 * TODO find a way to create another requirement */

// headers copied over from test_alarm_negative, so
// I do not know what they each are for.
#include <stdio.h>
#include "tests/threads/tests.h" /* location of extern */
//#include "threads/malloc.h"
//#include "threads/synch.h"
//#include "threads/thread.h"
//#include "devices/timer.h"

//Created externally in tests.h
void
test_custom_test (void)
{
  printf("Inside the custom test.");
  //Looks like this indicates that the test passes
  pass();
  // the alternate is calling fail();
}
