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

#define MAX_RELOCATION 5

// inspired by and based on LDCF of Zhang et al., doi: 10.1109/ICDE51399.2021.00087

bitset<32> to_bitset(string s) {
    auto binary = [](char c) { return c == '0' || c == '1'; };
    auto not_binary = [binary](char c) { return !binary(c); };

    s.erase(remove_if(begin(s), end(s), not_binary), end(s));

    return bitset<32>(s);
}

string to_string(bitset<32> bs) {
    return bs.to_string();
}

const string fingerprint(const string x) {
    cout << "called fingerprint function with argument x: " << x << endl;
    return x;
}

const string hashF(const string str){
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
    // cout << "hashF function for input " << str << " returning: " << retVal << endl;
    return retVal;
}

int checkCF(int s) {
    // to be implemented
    return 0;
}

const string getPrefix(const string x, int level) {
    // to be implemented
    return x;
}

int getChild(int loc, int i, string prefix) {
    // to be implemented
    return 0;
}

int generateRandom() {
    srand(time(NULL));
    return (rand() % 2);
}

bool CFfull(int CF) {
    // returns true if CF is full, false otherwise

    // to be implemented
    return false;
}

bool insert(const string x) {
    int root;
    int currentLevel = 0;
    int currentLoc = root;
    const string xi = fingerprint(x);
    const string mu = hashF(x);
    cout << "mu = " << mu << endl;
    string nu = to_string(to_bitset(mu) ^ to_bitset(hashF(mu))); // ^ bitwise xor
    // cout << typeid(nu).name() << endl;
    cout << "nu = " << nu << endl;

    string prefix;
    int i = 0;
    while(checkCF(currentLoc) == 0) {
        // should be checking if it is nullptr instead of 0
        ++currentLevel;
        prefix = getPrefix(xi, currentLevel);
        currentLoc = getChild(currentLoc, i, prefix);
        ++i;
    }
    int currentCF = checkCF(currentLoc);
    int bucketIndex = generateRandom();

    for(int i=0; i < MAX_RELOCATION; ++i) {
        // to be implemented
    }

    if(CFfull(currentCF)) {
        // to be implemented
    }

    return true;
}

int main() {
    string in = "ATTTGGTAACCACTGTACTGATTACGACG";
    insert(in);
}