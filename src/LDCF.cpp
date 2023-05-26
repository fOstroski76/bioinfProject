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
//#include "LDCF.h"
// #include "cuckoofilter.h"
#include "Localizing.h"

using namespace std;

#define MAX_RELOCATION 500

LDCF::LDCF(int totalCapacity, int singleTableLength, int bucketSize) {
    // cout << "in LDCF constructor" << endl;

    single_table_length = singleTableLength;
    bucket_size = bucketSize;
    total_capacity = totalCapacity;

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


    Localize loc;

    CuckooFilter* node = get_node();
    int right;
    bool successful_insert;
    CuckooFilter* parent = new CuckooFilter(node->get_single_table_length(), node->get_bucket_size(), (node->get_level())-1);
    while (node != nullptr && node->isFull) {
        right = loc.get_location(s);
        if (right == 1) {
            parent = node;
            node = node->get_right_child();
        }
        else if (right == 0) {
            parent = node;
            node = node->get_left_child();
        }
        else {
            cout << "nešta se krivo računa" << endl;
        }
    }
    cout << "tu4" << endl;
    if (node == nullptr) {
        // loop was exited because all previous are full
        node = parent;
        node->generate_children(node->get_single_table_length(), node->get_bucket_size(), node->level);
        right = loc.get_location(s);
        CuckooFilter* insertingCF;
        if (right) {
            CuckooFilter* insertingCF = node->get_right_child();
        }
        else {
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
        cout << "node->isFull = " << node->isFull << endl;
    }
    if (!successful_insert) {
        cout << "ulazim u dodavanje ponovno" << endl;
        node->generate_children(node->get_single_table_length(), node->get_bucket_size(), node->level);
        cout << "1" << endl;
        right = loc.get_location(s);

        cout << "2" << endl;
        CuckooFilter* insertingCF;
        if (right) {
            insertingCF = node->get_right_child();
            insertingCF->printContents();
            cout << "3" << endl;
        }
        else {
            insertingCF = node->get_left_child();
            cout << "4" << endl;
        }
        cout << "5" << endl;
        cout << insertingCF->get_bucket_size() << endl;
        successful_insert = insertingCF->tryInsert(s);
        cout << "insert successful: " << successful_insert << endl;
        cout << "added in new CF" << endl;

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

int LDCF::get_single_table_length() {
    return single_table_length;
}