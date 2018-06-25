#include <string>
#include <UnitTest++/UnitTest++.h>
#include "FormattedOutputBuffer.hh"

SUITE (FormattedOutputBuffer) {
    TEST (printf) {
        char buf[200];
        FormattedOutputBuffer fo(buf, 200);
        CHECK_EQUAL(8, fo.printFormatted("test:%d", 100));
        buf[8] = '\0';
        CHECK_EQUAL("test:100", std::string(buf));
    }
    TEST (printfTooSmallBuffer) {
        char buf[7] = "canary";
        FormattedOutputBuffer fo(buf, 3);
        CHECK_EQUAL(-1, fo.printFormatted("test:%d", 100));
        CHECK_EQUAL("tesary", std::string(buf));
    }
    TEST (setBuffer) {
        char buf1[3], buf2[200];
        FormattedOutputBuffer fo(buf1, 3);
        fo.printFormatted("test1:%d", 100);
        fo.setBuffer(buf2, 200);
        CHECK_EQUAL(9, fo.printFormatted("test2:%d", 200));
        buf2[9] = '\0';
        CHECK_EQUAL("test2:200", std::string(buf2));
    }
}