/* fixedpoint.h
 * This file contains function prototypes for
 * 17.14 formatted fixed-point conversion operations in Pintos.
 * These operations are necessary for the MLFQS portion
 * of Pintos-p1
 */

/* Created by Michael Hedrick and Matthew Moltzau
 * Team Chartreuse
 * CSCI 3453, UC Denver Spring 2018
 */
#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#define F 16384 // 2**q == 2**14 == 16384, Pintos manual B-6

typedef struct
  {
    int fixed_val; //32 bit (I think) for holding 17.14 representation fixed points
  } fixed_point;


int fix_to_int_floor (fixed_point x);     // convert fixed to int, round toward zero
int fix_to_int_round (fixed_point x);     // convert fixed to int, normal rounding
fixed_point int_to_fix (int n);           // convert integer to 17.14 fixed
fixed_point add_fix_fix (fixed_point x, fixed_point y); // add fixed pt values
fixed_point add_int_fix (fixed_point x, int n); // add an integer to a fixed point
fixed_point sub_fix_fix (fixed_point x, fixed_point y); // subtracted fix pt values
fixed_point sub_int_fix_(fixed_point x, int n); // sub an integer from a fixed point
fixed_point mul_fix_fix (fixed_point x, fixed_point y); // multiply two fixed points
fixed_point mul_int_fix (fixed_point x, int n);         // multiply an int and a fixed
fixed_point div_fix_fix (fixed_point x, fixed_point y); // divide a fixed by a fixed
fixed_point div_fix_int (fixed_point x, int n); // divide a fixed by an integer

#endif