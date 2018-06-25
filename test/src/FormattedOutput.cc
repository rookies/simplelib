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
    c = fo.printFormatted("%% %c %d %u %x %X %o %s", 'a', -42, 100, 0xdeadbeef, 0xdeadbeef, 042, "test123");
    std::cout << " -> " << c << std::endl;
}