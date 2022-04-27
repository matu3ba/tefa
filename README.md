# Tefa - Test Fast

Experiments with C, testing and abi.

Minimal, simple, fast and composable testing framework.

wip.

Goals:
1. Tooling(Examples): User configurable. Most common things. (Compiler flags, Diagnostics, Valgrind)
2. Portability: Types and behavior can be checked for all targets.
3. Clarity and explicity: User provides compiler flags from examples.
4. Minimal dependencies: No unnecessary things.
5. Follow standards, if good practice and dont, if not good practice.
6. Test framework must work with `-Weverything` and all common tools.

Nongoals:
1. Hack around compiler problems.
2. Silence any warnings.
3. For near future: Floating point checks.

Assumptions:
1. Integers have 2s complement.
2. Little endian.
3. false == 0, true == 1, ie (0 != 0) => 0, (0 == 0) => 1.
4. User writes necessary defines and checks for types from examples
   * C standard does not maintain an architecture list with types + sizes
   * Assumptions of code how to deal with implemention defined behavior must be done by author
     - string.h uses char, which may be signed or unsigned
     - C integer data types are only defined by their minimum size
     - C float data types are completely unspecified
     - Machine accuracy could be relevant (IEEE float or SIMD without assumptions)

Assertions:
1. 1 Byte represents 8 Bit.
2. char has 1 Byte size.
3. User or platform provided limits.h types have correct size and signedness (if specified).

#### Notes

typedefs
* can not be introspected, ie via macros
* are less annoying for multiline types (no \ before end of line necessary)
* prevent logic errors, ie for long MACRO => long `long int`
* conclusion
  - use macros, if you want simple reflection from external code
  - this can be often useful in headers
  - otherwise, especially for scoped symbols (in source files), use typedefs,
    if possible
