#include <UnitTest++/UnitTest++.h>
#include "Random.hh"

class RandomTest : public Random {
public:
    int getBit() override {
        return 0; // chosen by fair dice roll.
                  // guaranteed to be random.
    }
};

SUITE (Random) {
    TEST (number) {
        RandomTest rt;
        int res = 0;
        CHECK_EQUAL(0, rt.getNumber(&res, 0, 100));
        CHECK_EQUAL(42, res);
    }
}