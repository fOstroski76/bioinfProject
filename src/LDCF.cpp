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
// #include "cuckoofilter.h"
#include "Localizing.h"

using namespace std;

#define MAX_RELOCATION 500

LDCF::LDCF(int noOfInputs, size_t single_table_length, size_t bucket_size) {
    // cout << "in LDCF constructor" << endl;

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

bool LDCF::insert(string s) {

    // cout << "entering insert code" << endl;

    Localize loc;

    CuckooFilter* node = this->get_node();
    // cout << "node = " << node << endl;
    int right;
    bool successful_insert;
    // cout << "node->isFull = " << node->isFull << endl;
    while (node != nullptr && node->isFull) {
        // cout << "entered while" << endl;
        right = loc.get_location(s);
        if (right == 1) {
            node = node->get_right_child();
        }
        else if (right == 0) {
            node = node->get_left_child();
        }
        else {
            cout << "nešta se krivo računa" << endl;
        }
    }
    if (node == nullptr) {
        // loop was exited because all previous are full
        node->generate_children(node->get_single_table_length(), node->get_bucket_size(), node->level);
        right = loc.get_location(s);
        CuckooFilter* insertingCF;
        if (right) {
            cout << "right is 1" << endl;
            CuckooFilter* insertingCF = node->get_right_child();
        }
        else {
            cout << "right is 0" << endl;
            CuckooFilter* insertingCF = node->get_left_child();
        }
        successful_insert = insertingCF->tryInsert(s);
        cout << "insert successful: " << successful_insert << endl;
        cout << "added in new CF" << endl;

    }
    else if (!(node->isFull)) {
        // loop was exited because the first not full CF was found
        successful_insert = node->tryInsert(s);
        cout << "insert successful: " << successful_insert << endl;
        cout << "added to an existing CF" << endl;
    }
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