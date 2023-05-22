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
#include "CF.h"
#include "LDCF.h"

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

const string fingerprint(const string str) {
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

const string hash_f(const string str){
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

int checkCF(int s) {
    // to be implemented
    return 0;
}

int generate_random() {
    srand(time(NULL));
    return (rand() % 2);
}

int generate_random_max(int max) {
    srand(time(NULL));
    return (rand() % max);
}

CF* choose_random_CF(int bucket_size) {
    // TODO bucket should be class Bucket, not int
    int index = generate_random_max(bucket_size);
    // get CF from that index
}

string cut_prefix(string xi_x, string prefix) {
    // to be implemented
}

bool insert(const string x) {
    LDCF* root; // TODO correctly initialize!
    int current_level = 0;
    LDCF* current_loc = root;
    string xi_x = fingerprint(x);
    string mu_x = hash_f(x);
    cout << "mu_x = " << mu_x << endl;
    string nu_x = to_string(to_bitset(mu_x) ^ to_bitset(hash_f(xi_x))); // ^ bitwise xor
    cout << "nu_x = " << nu_x << endl;

    string prefix;
    int i = 0;
    while(current_loc->get_node()->empty == false) {
        // should be checking if it is nullptr instead of false
        ++current_level;
        prefix = current_loc->get_prefix(xi_x, current_level);
        current_loc = current_loc->get_child(current_loc, i, prefix);
        // ++i;
    }
    CF* currentCF = current_loc->get_node();
    const string bucket = generate_random() == 0 ? xi_x : mu_x;

    CF* xi_y;
    for(int r=0; i < MAX_RELOCATION; ++r) {
        xi_y = choose_random_CF(bucket.length());
        CF* victim = xi_y;
        xi_x = cut_prefix(xi_x, prefix);
        // to be implemented:
        // insert xi_x into currentCF.B(bucket)
        // victim = add_prefix(victim, pre);
        // bucket = bucket ^ hash_f(victim);
    }

    if(current_loc->get_node()->full) {
        // to be implemented:
        // current_loc = append(currentCF, current_level);
    }

    return true;
}

int main() {
    string in = "ATTTGGTAACCACTGTACTGATTACGACG";
    insert(in);
    return 0;
}