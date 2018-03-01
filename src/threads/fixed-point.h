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
#include <stddef.h>

#define F 16384 // 2**q == 2**14 == 16384, Pintos manual B-6

struct fp
{
    int val; //32 bit (I think) for holding 17.14 representation fixed points
};
typedef struct fp fixed_point;

/* FUNCTION PROTOTYPES */
static inline int fix_to_int_floor (const fixed_point x);
static inline int fix_to_int_round (const fixed_point x);
static inline int fix_get_dec (const fixed_point x);
static inline fixed_point int_to_fix (int n);

//Function overloading is not a c feature. Maybe using
//the macro _Generic would work, but idk how.
//static inline void print (const fixed_point);
//static inline void print (char*, const fixed_point);
//static inline void print (const fixed_point, char*);
static inline void print_fp (const char*, const fixed_point, const char*);

static inline fixed_point add_fix_fix (const fixed_point x, fixed_point y);
static inline fixed_point add_fix_int (const fixed_point x, int n);
static inline fixed_point sub_fix_fix (const fixed_point x, fixed_point y);
static inline fixed_point sub_fix_int (const fixed_point x, int n);

static inline fixed_point mul_fix_fix (const fixed_point x, fixed_point y);
static inline fixed_point mul_fix_int (const fixed_point x, int n);
static inline fixed_point div_fix_fix (const fixed_point x, fixed_point y);
static inline fixed_point div_fix_int (const fixed_point x, int n);

static inline bool fix_cmp_less (const fixed_point p1, const fixed_point p2);

// convert fixed to int, round toward zero
int fix_to_int_floor (const fixed_point x)  
{
    return (x.val / F);
}

// convert fixed to int, normal rounding
int fix_to_int_round (const fixed_point x) 
{
    if (x.val >= 0)
      return ((x.val + F / 2) / F);
    else
      return ((x.val - F / 2) / F);
}

//Not sure to what degree this is valid
int fix_get_dec (const fixed_point x)
{
    //2**14 == 16384, so a value of 2 would be: 32768
    int dec = x.val % F;
    long long tmp = dec * 100000;
    tmp /= F;
    return (int) tmp;
}

//maybe use snprintf to put result into char buffer?
//we honestly don't need it, so I wouldn't worry about it
/*
void print (const fixed_point x) {
    print ("", x, "");
}

void print (char *str1, const fixed_point x) {
    print (str1, x, "");
}

void print (const fixed_point x, char *str2) {
    print ("", x, str2);
}
*/
void print_fp (const char *str1, const fixed_point x, const char *str2) {
    int num = fix_to_int_floor (x);
    int dec = fix_get_dec (x);
    if (dec) {
        printf ("%s%d.%d%s", str1, num, dec, str2);
    } else {
        printf ("%s%d%s", str1, num, str2);
    }
}

// convert integer to 17.14 fixed
fixed_point int_to_fix (int n)  
{
    fixed_point fxp;
    fxp.val = n * F;
    return fxp;
}

// add fixed pt values
fixed_point add_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = x.val + y.val;
    return fxp;
}

// add an integer to a fixed point
fixed_point add_fix_int (const fixed_point x, int n) 
{
    fixed_point fxp;
    fxp.val = x.val + n * F;
    return fxp; 
}

// subtracted fix pt values
fixed_point sub_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = x.val + y.val;
    return fxp;
}

// sub an integer from a fixed point
fixed_point sub_fix_int (const fixed_point x, int n) 
{
    fixed_point fxp;
    fxp.val = (x.val - n * F);
    return fxp;
}

// multiply two fixed points
fixed_point mul_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = (int32_t) ((int64_t) x.val * y.val / F);
    return fxp;
}

// multiply an int and a fixed
fixed_point mul_fix_int (const fixed_point x, int n)
{
    fixed_point fxp;
    fxp.val = x.val * n;
    return fxp;
}

// divide a fixed by a fixed
fixed_point div_fix_fix (const fixed_point x, fixed_point y)
{
    fixed_point fxp;
    fxp.val = (int32_t) ((int64_t) x.val * F / y.val);
    return fxp;
}

// divide a fixed by an integer
fixed_point div_fix_int (const fixed_point x, int n)
{
    fixed_point fxp;
    fxp.val = (x.val / n);
    return fxp;
}

//TODO
bool fix_cmp_less (const fixed_point p1, const fixed_point p2)
{
    //compare int then compare dec,
    //OR just compare the values?
    //fix_get_dec (p1) < fix_get_dec (p2)
}

#endif
