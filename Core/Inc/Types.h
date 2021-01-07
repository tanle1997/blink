#ifndef _TYPES_H_

#define _TYPES_H_

typedef unsigned char       uint8;
typedef unsigned char       boolean;
typedef unsigned short int  uint16;
typedef unsigned int        uint32;
typedef unsigned long       ulint32;
typedef unsigned long long  uint64;
typedef signed char         sint8;
typedef signed int          sint16;
typedef signed long         sint32;
typedef signed long long    sint64;
typedef float               float32;
typedef double              float64;

#define TRUE    (boolean)1
#define FALSE   (boolean)0
#define PASSED  (boolean)1
#define FAILED  (boolean)0

#define NULL_PTR    (void *)0

#endif
