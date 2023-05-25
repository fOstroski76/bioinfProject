// code written by Elena & Fran

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
#include "LDCF.h"
#include "cuckoofilter.h"

using namespace std;

#define MAX_RELOCATION 500

LDCF::LDCF(int noOfInputs, size_t single_table_length, size_t bucket_size) {
    single_table_length = single_table_length;
    bucket_size = bucket_size;
    totalCapacity = noOfInputs;

    node = new CuckooFilter(single_table_length, bucket_size, 0);
    left_child = new CuckooFilter(single_table_length, bucket_size, 1);
    right_child = new CuckooFilter(single_table_length, bucket_size, 1);
    curr_level = curr_level;

}

CuckooFilter* LDCF::get_node() {
    return node;
}
CuckooFilter* LDCF::get_left_child() {
    return left_child;
}
CuckooFilter* LDCF::get_right_child() {
    return right_child;
}

bool LDCF::insert(const string s) {
    // to take the code from insert.cpp
    return true;
}

bool LDCF::query(const string s) {
    // to be implemented
    return true;
}

bool LDCF::del(const string s) {
    // to be implemented
    return true;
}

LDCF* LDCF::get_child(LDCF* node, int i, const string prefix) {
    // to be implemented
    return node;
}

const string LDCF::get_prefix(const string s, int level) {
    // to be implemented
    return s;
}