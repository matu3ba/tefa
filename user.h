// SPDX-License-Identifier: BSD0
// user configured logic.
//
// ------           ------>
// ------ test fast ------>
// ------           ------>

#ifdef TESTFAST_USER
#error "TESTFAST_USER already included"
#else
#define TESTFAST_USER

// necessary for testing
#include <stdint.h> // abi: (u)int8_t .. (u)int64_t

// optional (see below for usage)
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

// necessary for testing
#define assert(a) if( !( a ) )                            \
{                                                         \
    fprintf( stderr, "%s:%d assertion failure of (%s)\n", \
                             __FILE__, __LINE__, #a );    \
    exit(EXIT_FAILURE);                                            \
}                                                         \
_Static_assert(1, "") // assume: true == 1

// necessary for testing
#ifdef IS_SIGNED
#error "IS_SIGNED already defined"
#else
#define IS_SIGNED(Type) (((Type)-1) < 0)
#endif // IS_SIGNED

// optional, but recommended
#ifndef EXIT_SUCCESS
  #error "EXIT_SUCCESS undefined, usually 0"
#endif
#ifndef EXIT_FAILURE
  #error "EXIT_FAILURE undefined, usually 1"
#endif
static_assert(EXIT_SUCCESS == 0, "err: exit not 0");
static_assert(EXIT_FAILURE == 1, "err: exit not 1");
//#define EXIT_SUCCESS 0
//#define EXIT_FAILURE 1

// optional, but recommended (to adjust)
static_assert(IS_SIGNED(char),   "err: char is unsigned");

#endif // TESTFAST_USER
