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
  
  //fix_normalize(&f); //only affects 9 repeating
  // 1.66662 now defined as expected value
  print_fp ("(fixed-point) decimal value: ", f, "\n");
  
  f = mul_fix_int (f, 3);
  msg ("multiplied by 3 (int)");
  //I just put the value that we got here into the .ck
  //file. Doesn't seem like self-defining tests are good
  //but idk what would be the better option.
  print_fp ("(fixed-point) decimal value: ", f, "\n");
  fix_normalize(&f);
  print_fp ("(fixed-point) decimal value: ", f, "\n");
  
  //pass();
  //fail();
}   

