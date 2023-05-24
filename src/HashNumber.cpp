// code written by Elena

#include <string>
#include <stdint.h>
#include <math.h>
#include "HashNumber.h"

using namespace std;

uint64_t HashNumber::hash_to_number(const string &hash) {
    uint64_t retVal = 0;
    int size = 0;
    for (char c : hash) {
            // cout << "c = " << c << "; adding " << uint64_t(pow(10, size*3) * static_cast<int>(c)) << endl;
            retVal += uint64_t(pow(10, size*3) * static_cast<int>(c));
            ++size;
    }
    // cout << "retVal of number = " << retVal << endl;
    return retVal;
}

string HashNumber::number_to_hash(uint64_t number, int substr_len) {
    string retVal = "";
    for (int i = 0; i < substr_len; i++) {
        // cout << number % 1000 << endl;
        retVal += number % 1000;
        number /= 1000;
    }
    return retVal;
} 


// uint64_t hash_to_number(const string &hash) {
//     uint retVal = 0;
//     for (string::size_type i = 0; i < hash.size(); i++) {
//             retVal += pow(8, i) * static_cast<int>(hash[i]);
//             cout << "hash[i] = " << hash[i] << "; adding " << pow(8, i) * static_cast<int>(hash[i]) << endl;
//     }
//     cout << "retVal of number = " << retVal << endl;
//     return retVal;
// }

// string number_to_hash(uint64_t number) {
//     string retVal = "";
//     for (int i = 2; i > -1; --i) {
//         cout << "number = " << number << endl;
//         cout << pow(8, i) << endl;
//         cout << number / uint64_t(pow(8, i)) << endl;
//         cout << "ovo između: " << number % uint64_t(pow(8, i));
//         retVal = to_string(number / uint64_t(pow(8, i))) + retVal;
//         cout << "retVal = " << retVal << endl;
//         number -= number % uint64_t(pow(8, i));
//     }
//     return retVal;
// } 