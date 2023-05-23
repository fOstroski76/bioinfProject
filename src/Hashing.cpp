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
#include "Hashing.h"

using namespace std;

const string Hashing::fingerprint(const string str) {
    // for now calculated in the same way as hash_f
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    const string retVal = ss.str();

    cout << "fingerprint function for input " << str << " returning: " << retVal << endl;
    return retVal;
}

const string Hashing::hash_f(const string str){
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    const string retVal = ss.str();
    // cout << "hash_f function for input " << str << " returning: " << retVal << endl;
    return retVal;
}
