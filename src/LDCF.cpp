// code written by Elena

// because of SHA256Init function, has to be run with: g++ -I/usr/include/openssl/ nameOfFile.cpp -lcrypto
// or need to add "-I/usr/include/openssl/" and "-lcrypto" as arguments in tasks.json if using vscode


/*
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
#include "CF.h"

using namespace std;

#define MAX_RELOCATION 5

LDCF::LDCF(size_t list_size, int capacity, int curr_level) {
    list_size = list_size;
    capacity = capacity;
    curr_level = curr_level;

    node = new CF(list_size, bucket_capacity, curr_level);
    left_child = new CF(list_size, bucket_capacity, curr_level+1);
    right_child = new CF(list_size, bucket_capacity, curr_level+1);
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
}

bool LDCF::query(const string s) {
    // to be implemented
}

bool LDCF::del(const string s) {
    // to be implemented
}

LDCF* LDCF::get_child(LDCF* node, int i, const string prefix) {
    // to be implemented
}

const string LDCF::get_prefix(const string s, int level) {
    // to be implemented
}

*/