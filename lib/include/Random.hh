#pragma once

/**
 * Abstract class, makes randomness from various sources usable in an easy way.
 *
 * Inherited classes have to implement the getBit() method where the actual
 * (pseudo)randomness comes from.
 */
class Random {
public:
    /**
     * Returns a random bit.
     *
     * @return the random bit (one or zero) on success, a negative number if an error occurs
     */
     virtual int getBit() = 0;

     /**
      * Returns a random number from the given range.
      *
      * @param result a pointer where the random number is written to
      * @param min the start of the range (inclusive)
      * @param max the end of the range (inclusive)
      * @return zero on success, negative number if an error occurs
      */
      int getNumber(int *result, int min, int max);
};