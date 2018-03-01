/* fixed-point.h
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

typedef struct fixed
  {
    int val; //32 bit (I think) for holding 17.14 representation fixed points
  } fixed_point;

// convert fixed to int, round toward zero
static inline int 
fix_to_int_floor (fixed_point x)  
{
    return (x.val / F);
}  

// convert fixed to int, normal rounding
static inline int 
fix_to_int_round (fixed_point x) 
{
    // best practices guide says to always use brackets
    // even with one line conditionals
    if (x.val >= 0)
    {
        return ((x + F / 2) / F);
    } 
    else
    {
        return ((x - F / 2) / F);
    }
}  

// convert integer to 17.14 fixed
static inline fixed_point 
int_to_fix (int n)  
{
    fixed_point fxp;
    fxp->val = n * F
    return fxp;
}   

// add fixed pt values
static inline fixed_point  
add_fix_fix (fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp->val = x.val + y.val;
    return fxp;
}

// add an integer to a fixed point
static inline fixed_point  
add_int_fix (fixed_point x, int n) 
{
    fixed_point fxp;
    fxp->val = x.val + n * F;
    return (fxp); 
}

// subtracted fix pt values
static inline fixed_point 
sub_fix_fix (fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp->val = x.val + y.val;
    return (fxp);
}

// sub an integer from a fixed point
static inline fixed_point 
sub_int_fix_(fixed_point x, int n) 
{
    fixed_point fxp;
    fxp->val = (x.val - n * F);
    return (fxp);
}

// multiply two fixed points
static inline fixed_point 
mul_fix_fix (fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp->val = (int32_t)((int64_t)x.val * y.val / F)
    return (fxp);;
}

// multiply an int and a fixed
static inline fixed_point 
mul_int_fix (fixed_point x, int n)
{
    fixed_point fxp;
    fxp->val = x.val * n;
    return (fxp);
}

// divide a fixed by a fixed
static inline fixed_point 
div_fix_fix (fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp->val = (int32_t)((int64_t)x.val * F / y.val)
    return (fxp);
}

// divide a fixed by an integer
static inline fixed_point 
div_fix_int (fixed_point x, int n)
{
    fixed_point fxp;
    fxp->val = x.val / n);
    return (fxp);
}
#endif
