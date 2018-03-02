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
#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define F 16384 // 2**q == 2**14 == 16384, Pintos manual B-6

struct fp
{
    int val; //32 bit (I think) for holding 17.14 representation fixed points
};
typedef struct fp fixed_point;


static inline int 
fix_to_int_floor (const fixed_point x)  
{
    return (x.val / F);
}

// convert fixed to int, normal rounding
static inline int 
fix_to_int_round (const fixed_point x) 
{
    if (x.val >= 0)
      return ((x.val + F / 2) / F);
    else
      return ((x.val - F / 2) / F);
}

//Not sure to what degree this is valid
static inline int 
fix_get_dec (const fixed_point x)
{
    //2**14 == 16384, so a value of 2 would be: 32768
    int dec = x.val % F;
    long long tmp = dec * 100000;
    tmp /= F;
    return (int) tmp;
}

static inline 
void fix_set_dec (fixed_point *x, int dec)
{
    long long tmp = dec * F / 100000;
    x->val = fix_to_int_floor (*x) | tmp;
}

static inline void 
print_fp (const char *str1, const fixed_point x, const char *str2) {
    int num = fix_to_int_floor (x);
    int dec = fix_get_dec (x);
    if (dec) {
        printf ("%s%d.%d%s", str1, num, dec, str2);
    } else {
        printf ("%s%d%s", str1, num, str2);
    }
}

// convert integer to 17.14 fixed
static inline fixed_point 
int_to_fix (int n)  
{
    fixed_point fxp;
    fxp.val = n * F;
    return fxp;
}

// add fixed pt values
static inline fixed_point 
add_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = x.val + y.val;
    return fxp;
}

// add an integer to a fixed point
static inline fixed_point 
add_fix_int (const fixed_point x, int n) 
{
    fixed_point fxp;
    fxp.val = x.val + n * F;
    return fxp; 
}

// subtracted fix pt values
static inline fixed_point 
ub_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = x.val + y.val;
    return fxp;
}

// sub an integer from a fixed point
static inline fixed_point 
sub_fix_int (const fixed_point x, int n) 
{
    fixed_point fxp;
    fxp.val = (x.val - n * F);
    return fxp;
}

// multiply two fixed points
static inline fixed_point 
mul_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = (int32_t) ((int64_t) x.val * y.val / F);
    return fxp;
}

// multiply an int and a fixed
static inline fixed_point 
mul_fix_int (const fixed_point x, int n)
{
    fixed_point fxp;
    fxp.val = x.val * n;
    return fxp;
}

// divide a fixed by a fixed
static inline fixed_point 
div_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = (int32_t) ((int64_t) x.val * F / y.val);
    return fxp;
}

// divide a fixed by an integer
static inline fixed_point 
div_fix_int (const fixed_point x, int n)
{
    fixed_point fxp;
    fxp.val = (x.val / n);
    return fxp;
}

//TODO
/*
//Some reason this function declaration caused errors and 
//couldn't be found by the compiler, telling me the above
//function prototype was declared static but never defined.
bool fix_cmp_less (const fixed_point p1, const fixed_point p2) UNUSED
{
    //compare int then compare dec,
    //OR just compare the values?
    //fix_get_dec (p1) < fix_get_dec (p2)
} */

/* Nomralize
 * if n decimals are repeating, continue that pattern
 * if 9 is repeating, round (this is the only working functionality)
 * TODO 0 repeating floor?
 */
/* UPDATE: What I wanted to fix initially is impossible
 * Suppose you want to normalize 0.66662 (whose
 * representation in fix is 10922), you can't get 
 * any closer. It isn't like each digit is an index
 * of an array that can be changed. The only other
 * close values are 10923 (0.66668), 10921 (0.66656),
 * or even 10924 (0.66674). Maybe some comparison can
 * be made so that you can get the closest value, but 
 * this would be more expensive than it needs to be. */
static inline void 
fix_normalize (fixed_point *x) {
    int count[10] = {0};
    int num= 0;
    
    int dec = fix_get_dec (*x);
    //we will be getting lowest digits first 
    //the final addition should have the largest
    //count (need 3 for majority)
    //if the final addition has a count >= 3 it is repeating 
    //printf("%d\n", dec);
    while (dec > 0) {
        num = dec % 10;
        ++count[num];
        dec /= 10;
    }
    
    if (count[num] >= 3) {
        if (num == 9) {
            (*x) = int_to_fix (fix_to_int_round (*x));
            return;
        }
        for (int i = 0; i < 5; ++i) {
            dec *= 10;
            dec += num;
        }
        long long tmp = (dec * F) / 100000;
        x->val = (fix_to_int_floor (*x) * F) | tmp;
    }
}

#endif
