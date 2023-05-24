// code written by Elena

#include <string>
#include <stdint.h>

using namespace std;

class HashNumber {
    public:
        uint64_t hash_to_number(const string &hash);

        string number_to_hash(uint64_t number, int substr_len);


};
