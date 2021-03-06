#include <sstream>
#include <UnitTest++/UnitTest++.h>
#include "FormattedOutput.hh"

class FormattedOutputTest : public FormattedOutput {
public:
    int printChar(char c) override {
        ss << c;
        return 0;
    }
    std::stringstream ss;
};

SUITE (FormattedOutput) {
    TEST (unsignedDecimalInteger) {
        FormattedOutputTest fo;
        CHECK_EQUAL(9, fo.printUnsignedInt(123456789));
        CHECK_EQUAL("123456789", fo.ss.str());
    }
    TEST (unsignedHexadecimalInteger) {
        FormattedOutputTest fo;
        CHECK_EQUAL(8, fo.printUnsignedInt(0xdeadbeef, 16));
        CHECK_EQUAL("deadbeef", fo.ss.str());
        fo.ss.str("");
        CHECK_EQUAL(8, fo.printUnsignedInt(0xdeadbeef, 16, true));
        CHECK_EQUAL("DEADBEEF", fo.ss.str());
    }
    TEST (unsignedBinaryInteger) {
        FormattedOutputTest fo;
        CHECK_EQUAL(4, fo.printUnsignedInt(0b1011, 2));
        CHECK_EQUAL("1011", fo.ss.str());
    }
    TEST (unsignedInvalidBase) {
        FormattedOutputTest fo;
        CHECK_EQUAL(-1, fo.printUnsignedInt(123, 17));
        CHECK_EQUAL(-1, fo.printUnsignedInt(123, 0));
        CHECK_EQUAL(-1, fo.printUnsignedInt(123, 1));
    }
    TEST (signedDecimalInteger) {
        FormattedOutputTest fo;
        CHECK_EQUAL(3, fo.printSignedInt(-42));
        CHECK_EQUAL("-42", fo.ss.str());
    }
    TEST (signedHexadecimalInteger) {
        FormattedOutputTest fo;
        CHECK_EQUAL(5, fo.printSignedInt(-0xdead, 16));
        CHECK_EQUAL("-dead", fo.ss.str());
        fo.ss.str("");
        CHECK_EQUAL(5, fo.printSignedInt(-0xdead, 16, true));
        CHECK_EQUAL("-DEAD", fo.ss.str());
    }
    TEST (signedBinaryInteger) {
        FormattedOutputTest fo;
        CHECK_EQUAL(5, fo.printSignedInt(-0b1011, 2));
        CHECK_EQUAL("-1011", fo.ss.str());
    }
    TEST (string) {
        FormattedOutputTest fo;
        CHECK_EQUAL(7, fo.printString("test123"));
        CHECK_EQUAL("test123", fo.ss.str());
    }
    TEST (printf) {
        FormattedOutputTest fo;
        int c = 0;
        CHECK_EQUAL(48, fo.printFormatted("%d %i %u %o %x %X %c %s %p %n %%",
                                           -42, -1337, 666, 042, 0xdeadbeef, 0xbadcab1e, 'a', "test", 0, &c));
        CHECK_EQUAL("-42 -1337 666 42 deadbeef BADCAB1E a test 0x0  %", fo.ss.str());
        CHECK_EQUAL(46, c);
    }
}