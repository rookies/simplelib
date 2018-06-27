simplelib
=========
This is a C++ library for very basic functionality, usually provided by the standard library.

The library itself works without any dependencies, it doesn't use the C/C++ standard library,
except some header files. Therefore it can be used for e.g. own kernels or embedded software.

The tests use [UnitTest++](https://github.com/unittest-cpp/unittest-cpp).

**Work in Progress.**

## Functionality
This is a list of the currently implemented functionality.

### FormattedOutput
An abstract class that provides methods for formatted data output.
Implementing classes only have to define a *printChar()* method.

Implemented methods:
 * print integers (signed/unsigned, in different bases 2..16, upper-/lowercase)
 * print strings (c-style)
 * print formatted (like printf, **incomplete**: no support for floats, flags, width, precision, length)

Included implementing classes:
 * **FormattedOutputBuffer** - writes into a buffer (just a *char*-array), with bounds-checking

Planned improvements:
 * print floats
 * support for floats, flags, width, precision, length in *printFormatted()*