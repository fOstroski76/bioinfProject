// code written by Elena

// because of SHA256Init function, has to be run with: g++ -I/usr/include/openssl/ nameOfFile.cpp -lcrypto
// or need to add "-I/usr/include/openssl/" and "-lcrypto" as arguments in tasks.json if using Visual Studio Code

#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include "Hashing.h"
#include "HashNumber.h"

using namespace std;

// returns string of bitset
string Hashing::to_string(bitset<32> bs) {
    return bs.to_string();
}

// creates fingerprint of input string
string Hashing::fingerprint(string str) {
    int fgpt_len = 6;
    HashNumber hn;
    Hashing hashing;

    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    string hash_str = ss.str();
    string hash_substr = hash_str.substr(0, fgpt_len);
    uint64_t hash_substr_int = hn.hash_to_number(hash_substr);
    string input_substr = str.substr(0, fgpt_len);
    uint64_t input_substr_int = hn.hash_to_number(input_substr);

    string retVal = hashing.to_string(hash_substr_int ^ input_substr_int); // ^ bitwise xor

    return retVal;
}

// creates SHA256 hash of input string (bzcket address)
string Hashing::hash_f(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    
    return ss.str();
}

// calculates alternative bucket address
string Hashing::second_hash_f(uint64_t mu_x_int, const string xi_x) {
    // returns nu_x = h1 XOR hash(xi_x)
    // mu_x_int is h1 as number; xi_x is fingerprint (using standard CF variable names)

    Hashing hashing;
    HashNumber hn;
    string xi_x_hash = hashing.hash_f(xi_x);
    uint64_t xi_x_hash_int = hn.hash_to_number(xi_x_hash);
    string nu_x = hashing.to_string(mu_x_int ^ xi_x_hash_int); // ^ bitwise xor
    
    return nu_x;
}