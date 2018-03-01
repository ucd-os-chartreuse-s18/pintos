#include <stdio.h>
#include "tests/threads/tests.h" /* location of extern */
#include "threads/fixed-point.h" 

void
test_fixed_point (void)
{
  //TODO test the following:
  //add_fix_fix
  //sub_fix_fix
  //mul_fix_fix
  //mul_int_fix
  //div_fix_fix
  //compare?
  
  fixed_point f = int_to_fix (10);
  msg ("fix = 10");
  msg ("fix to int floor is %d", fix_to_int_floor (f));
  msg ("fix to int round is %d", fix_to_int_round (f));
  print_fp ("(fixed-point) decimal value: ", f, "\n");
  
  f = sub_fix_int (f, 6);
  msg ("subtracted 6 (int)");
  f = add_fix_int (f, 1);
  msg ("added 1 (int)");
  
  //the printf is called in an external file, so I have 
  //to explictly say "fixed-point" here
  print_fp ("(fixed-point) decimal value: ", f, "\n");
  
  f = div_fix_int (f, 3);
  msg ("divided by 3 (int)");
  msg ("fix to int floor is %d", fix_to_int_floor (f));
  msg ("fix to int round is %d", fix_to_int_round (f));
  //should display about 1.666. Not sure how it should be
  //tested for output, since knowing the exact number of
  //decimal places is iffy, and I don't know if hardcoding
  //it is just what we're supposed to do
  //print_fp ("(fixed-point) decimal value: ", f, "\n");
  
  //we have to round here to get the right number
  //we should try to see if we can be more accurate
  f = mul_fix_int (f, 3);
  msg ("multiplied by 3 (int)");
  //f = int_to_fix (fix_to_int_round (f));
  print_fp ("(fixed-point) decimal value: ", f, "\n");
  
  //pass();
  //fail();
}   

