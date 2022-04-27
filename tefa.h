// SPDX-License-Identifier: BSD0
// tefa main logic
//
// ------           ------>
// ------ test fast ------>
// ------           ------>

#ifdef TESTFAST
#error "TESTFAST already included"
#else
#define TESTFAST

#include "user.h"

// less annoyance (user might use i8,u8 instead)?
// char implementation defined (desktop typically signed)
typedef signed char   tefa_i8;
typedef uint8_t       tefa_u8;
typedef uint16_t      tefa_u16;
typedef uint32_t      tefa_u32;
typedef uint64_t      tefa_u64;
//typedef uint128_t   tefa_u128; // C abi problems
//typedef uint256_t   tefa_u256; // C abi problems
typedef unsigned char tefa_u8;
typedef int8_t        tefa_i8;
typedef int16_t       tefa_i16;
typedef int32_t       tefa_i32;
typedef int64_t       tefa_i64;
//typedef int128_t    tefa_i128; // C abi problems
//typedef int256_t    tefa_i256; // C abi problems

static_assert(sizeof(char) == 1, "err: char not 1 byte");

static_assert(IS_SIGNED(signed char), "err: IS_SIGNED signed char");
static_assert(sizeof(signed char) == 1, "err: char not 1 byte");
static_assert(sizeof(int8_t) == 1,  "err: int8_t not 1 byte");
static_assert(sizeof(int16_t) == 2, "err: int16_t not 2 byte");
static_assert(sizeof(int32_t) == 4, "err: int32_t not 4 byte");
static_assert(sizeof(int64_t) == 8, "err: int64_t not 8 byte");

static_assert((!IS_SIGNED(unsigned char)), "err: IS_SIGNED unsigned char");
static_assert(sizeof(unsigned char) == 1, "err: char not 1 byte");
static_assert(sizeof(uint8_t) == 1,  "err: uint8_t not 1 byte");
static_assert(sizeof(uint16_t) == 2, "err: uint16_t not 2 byte");
static_assert(sizeof(uint32_t) == 4, "err: uint32_t not 4 byte");
static_assert(sizeof(uint64_t) == 8, "err: uint64_t not 8 byte");

#endif // TESTFAST
