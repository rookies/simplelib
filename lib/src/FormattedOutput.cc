#include "FormattedOutput.hh"

#include <cstdarg>

int FormattedOutput::printUnsignedInteger(uintmax_t n, unsigned char base, bool uppercase) {
    // check base (only up to 16 supported)
    if (base > 16) return -1;

    int count = 0;
    if (n / base != 0) {
        count = printUnsignedInteger(n / base, base, uppercase);
    };
    if (uppercase) {
        printChar(numberCharsUppercase[n % base]);
    } else {
        printChar(numberCharsLowercase[n % base]);
    };
    return count + 1;
}

int FormattedOutput::printSignedInteger(intmax_t n, unsigned char base, bool uppercase) {
    if (n < 0) {
        printChar('-');
        int res = printUnsignedInteger(-n, base, uppercase);
        if (res < 0) return res;
        return res + 1;
    } else {
        return printUnsignedInteger(n, base, uppercase);
    };
}

int FormattedOutput::printString(const char *s) {
    int count;

    for (count = 0; char c = *s++; ++count) {
        printChar(c);
    }
    return count;
}

int FormattedOutput::printFormatted(const char *format, ...) {
    // argument list
    va_list arg;
    va_start(arg, format);
    // result of sub-calls
    int res;
    // currently in a format specifier?
    bool in_format = false;
    // already written characters
    int count = 0;

    // variables for arguments
    uintmax_t val_ui;
    intmax_t val_si;
    uintptr_t val_ptr;
    char *val_str;
    signed int *val_cptr;

    // TODO: flags, width, precision, length
    while (char c = *format++) {
        if (c == '%' && !in_format) {
            // percent character, format specifier starts (if not already started)
            in_format = true;
        } else if (in_format) {
            // we're in a format specifier, check the character
            switch (c) {
                case 'd':
                case 'i':
                    // signed decimal integer
                    val_si = va_arg(arg, int);
                    res = printSignedInteger(val_si);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                case 'u':
                    // unsigned decimal integer
                    val_ui = va_arg(arg, unsigned int);
                    res = printUnsignedInteger(val_ui);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                case 'o':
                    // unsigned octal
                    val_ui = va_arg(arg, unsigned int);
                    res = printUnsignedInteger(val_ui, 8);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                case 'x':
                    // unsigned hexadecimal integer
                    val_ui = va_arg(arg, unsigned int);
                    res = printUnsignedInteger(val_ui, 16, false);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                case 'X':
                    // unsigned hexadecimal integer (uppercase)
                    val_ui = va_arg(arg, unsigned int);
                    res = printUnsignedInteger(val_ui, 16, true);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                    // TODO: floating point numbers %f, %F, %e, %E, %g, %G, %a, %A
                case 'c':
                    // character
                    val_si = va_arg(arg, int);
                    printChar(static_cast<char>(val_si));
                    count++;
                    in_format = false;
                    break;
                case 's':
                    // string of characters
                    val_str = va_arg(arg, char*);
                    res = printString(val_str);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                case 'p':
                    // pointer address
                    val_ptr = reinterpret_cast<uintptr_t>(va_arg(arg, void*));
                    res = printString("0x");
                    if (res < 0) return res;
                    count += res;
                    res = printUnsignedInteger(val_ptr, 16, false);
                    if (res < 0) return res;
                    count += res;
                    in_format = false;
                    break;
                case 'n':
                    // print nothing, get number of characters written so far
                    val_cptr = va_arg(arg, signed int*);
                    *val_cptr = count;
                    in_format = false;
                    break;
                case '%':
                    // literal percent character
                    printChar('%');
                    count++;
                    in_format = false;
                    break;
                default:
                    in_format = false;
            }
        } else {
            // simple character, print it
            printChar(c);
            count++;
        }
    }

    va_end(arg);
    return count;
}

const char FormattedOutput::numberCharsLowercase[] = "0123456789abcdef";
const char FormattedOutput::numberCharsUppercase[] = "0123456789ABCDEF";