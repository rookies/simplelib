#pragma once

#include <cstdint>

/**
 * Abstract class, formats data and puts it to an arbitrary output.
 *
 * Inherited classes have to implement the printChar() method which
 * defines where the output is written to.
 */
class FormattedOutput {
public:
    /**
     * Prints a character.
     *
     * @param c the character to print
     * @return zero on success or a negative number if an error occurs
     */
    virtual int printChar(char c) = 0;

    /**
     * Prints an unsigned integer in a given base (default is 10).
     *
     * @param n the integer to print
     * @param base the base to print the integer in
     * @return number of printed characters or a negative number if an error occurs
     */
    int printUnsignedInt(uintmax_t n, unsigned char base = 10, bool uppercase = false);

    /**
     * Prints a signed integer in a given base (default is 10).
     *
     * @param n the integer to print
     * @param base the base to print the integer in
     * @return number of printed characters or a negative number if an error occurs
     */
    int printSignedInt(intmax_t n, unsigned char base = 10, bool uppercase = false);

    /**
     * Prints a c-style string (null-terminated char array).
     *
     * @param s the string to print
     * @return number of printed characters or a negative number if an error occurs
     */
    int printString(const char *s);

    /**
     * Prints data using a format string.
     *
     * @param format the format string
     * @param ... the data to print
     * @return number of printed characters or a negative number if an error occurs
     *
     * @todo %f, %F, %e, %E, %g, %G, %a, %A
     * @todo flags, width, precision, length
     */
     int printFormatted(const char *format, ...);

    /**
     * Arrays of chars which are used to print numbers, lowercase and uppercase.
     */
    static const char numberCharsLowercase[];
    static const char numberCharsUppercase[];
};