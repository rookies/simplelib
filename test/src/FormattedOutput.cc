#include <iostream>
#include "FormattedOutput.hh"

class TestFormattedOutput : public FormattedOutput {
public:
    void printChar(char c) override;
};

void TestFormattedOutput::printChar(char c) {
    std::cout << c;
}

int main() {
    TestFormattedOutput fo;
    int c;
    signed int c_test;

    c = fo.printUnsignedInteger(123456789);
    std::cout << " -> " << c << std::endl;
    c = fo.printUnsignedInteger(0xdeadbeef, 16);
    std::cout << " -> " << c << std::endl;
    c = fo.printUnsignedInteger(0xdeadbeef, 16, true);
    std::cout << " -> " << c << std::endl;
    c = fo.printUnsignedInteger(123, 20);
    std::cout << " -> " << c << std::endl;
    c = fo.printSignedInteger(-42);
    std::cout << " -> " << c << std::endl;
    c = fo.printString("test123");
    std::cout << " -> " << c << std::endl;
    c = fo.printFormatted("%d %i %u %o %x %X ... %c %s %p %n %%",
            -42, -1337, 666, 042, 0xdeadbeef, 0xbadcab1e, 'a', "test", main, &c_test);
    std::cout << " -> " << c_test << " -> " << c << std::endl;
    c = printf("%d %i %u %o %x %X ... %c %s %p %n %%",
           -42, -1337, 666, 042, 0xdeadbeef, 0xbadcab1e, 'a', "test", main, &c_test);
    std::cout << " -> " << c_test << " -> " << c << std::endl;
}