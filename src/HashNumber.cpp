// code written by Elena

#include <string>
#include <stdint.h>
#include <math.h>
#include "HashNumber.h"

using namespace std;

// casts hash to a decadal-based number 
uint64_t HashNumber::hash_to_number(const string &hash) {
    uint64_t retVal = 0;
    int size = 0;
    for (char c: hash) {
            retVal += uint64_t(pow(10, size*3) * static_cast<int>(c));
            ++size;
    }
    return retVal;
}

// casts a decadal-based number representation of a hash back to hash
string HashNumber::number_to_hash(uint64_t number, int substr_len) {
    string retVal = "";
    for (int i = 0; i < substr_len; i++) {
        retVal += number % 1000;
        number /= 1000;
    }
    return retVal;
} 