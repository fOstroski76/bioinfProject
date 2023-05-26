// code written by Elena

// because of SHA256Init function, has to be run with: g++ -I/usr/include/openssl/ nameOfFile.cpp -lcrypto
// or need to add "-I/usr/include/openssl/" and "-lcrypto" as arguments in tasks.json if using vscode

#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>     // rand, rand
#include <time.h>       // time

using namespace std;

class Hashing {
    public:

        string to_string(bitset<32> bs);

        string fingerprint(string str);

        string hash_f(const string str);

        string second_hash_f(uint64_t mu_x_int, const string xi_x);

};
