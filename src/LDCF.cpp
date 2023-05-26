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
#include "Localizing.h"
#include "Hashing.h"

using namespace std;

#define MAX_RELOCATION 500

// constructor for LDCF object
LDCF::LDCF(int totalCapacity, int singleTableLength, int bucketSize) {
    
    single_table_length = singleTableLength;
    bucket_size = bucketSize;
    total_capacity = totalCapacity;

    node = new CuckooFilter(single_table_length, bucket_size, 0);
    left_child = new CuckooFilter(single_table_length, bucket_size, 1);
    right_child = new CuckooFilter(single_table_length, bucket_size, 1);
    curr_level = curr_level;

}

// returns current node of LDCF
CuckooFilter* LDCF::get_node() {
    return node;
}

// returns left child of current node of LDCF
CuckooFilter* LDCF::get_left_child() {
    return left_child;
}

// returns right child of current node of LDCF
CuckooFilter* LDCF::get_right_child() {
    return right_child;
}

// inserts input string s into LDCF. returns true if successful, false otherwise
bool LDCF::insert(string s) {

    Localize loc;
    Hashing h;
    string fgpt = h.fingerprint(s);

    CuckooFilter* node = get_node();
    int right;
    bool successful_insert;
    CuckooFilter* parent = new CuckooFilter(node->get_single_table_length(), node->get_bucket_size(), (node->get_level())-1);
    while (node != nullptr && node->isFull) {
        right = loc.get_location(fgpt, node->level);
        if (right == 1) {
            parent = node;
            node = node->get_right_child();
        }
        else if (right == 0) {
            parent = node;
            node = node->get_left_child();
        }
    }
    if (node == nullptr) {
        // loop was exited because all previous nodes are full
        node = parent;
        node->generate_children(node->get_single_table_length(), node->get_bucket_size(), node->level);
        right = loc.get_location(fgpt, node->level);
        CuckooFilter* insertingCF;
        if (right) {
            insertingCF = node->get_right_child();
        }
        else {
            insertingCF = node->get_left_child();
        }
        successful_insert = insertingCF->tryInsert(s);
    } else if (!(node->isFull)) {
        // loop was exited because the first not full CF was found
        successful_insert = node->tryInsert(s);
    }

    if (!successful_insert) {
        node->generate_children(node->get_single_table_length(), node->get_bucket_size(), node->level);
        right = loc.get_location(fgpt, node->level);

        CuckooFilter* insertingCF;
        if (right) {
            insertingCF = node->get_right_child();
            insertingCF->printContents();
        }
        else {
            insertingCF = node->get_left_child();
        }
        successful_insert = insertingCF->tryInsert(s);
    }

    return true;
}

// queries string in LDCF. returns true if found, false otherwise
bool LDCF::query(const string s) {
    Localize loc;
    Hashing h;
    string fgpt = h.fingerprint(s);

    CuckooFilter* node = get_node();

    int right;
    bool found = false;
    CuckooFilter* parent = new CuckooFilter(node->get_single_table_length(), node->get_bucket_size(), (node->get_level())-1);
    while (node != nullptr) {
        found = node->query(s);
        if (found) {
            return true;
        }
        if (!found) {
            right = loc.get_location(fgpt, node->level);
            if (right == 1) {
                parent = node;
                node = node->get_right_child();
            }
            else if (right == 0) {
                parent = node;
                node = node->get_left_child();
            }
        }
    }
    return false;
    
}

// deletes string from LDCF. returns true if successful, false otherwise
bool LDCF::del(const string s) {
    Localize loc;
    Hashing h;
    string fgpt = h.fingerprint(s);

    CuckooFilter* node = get_node();

    int right;
    bool deleted = false;
    CuckooFilter* parent = new CuckooFilter(node->get_single_table_length(), node->get_bucket_size(), (node->get_level())-1);
    while (node != nullptr) {
        deleted = node->deleteItem(s);
        if (deleted) {
            return true;
        }
        if (!deleted) {
            right = loc.get_location(fgpt, node->level);
            if (right == 1) {
                parent = node;
                node = node->get_right_child();
            }
            else if (right == 0) {
                parent = node;
                node = node->get_left_child();
            }
        }
    }
    return false;
}

// returns CF size (number of buckets in CF)
int LDCF::get_single_table_length() {
    return single_table_length;
}