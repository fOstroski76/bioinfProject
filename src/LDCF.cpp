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
#include "LDCF.h"
// #include "CF.h"

using namespace std;

#define MAX_RELOCATION 500

LDCF::LDCF(size_t list_size, size_t bucket_size) {
    list_size = list_size;
    bucket_size = bucket_size;

    node = new CF(list_size, bucket_size);
    left_child = new CF(list_size, bucket_size);
    right_child = new CF(list_size, bucket_size);
    curr_level = curr_level;

}

CF* LDCF::get_node() {
    return node;
}
CF* LDCF::get_left_child() {
    return left_child;
}
CF* LDCF::get_right_child() {
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