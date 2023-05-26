// code written by Elena

#include <iostream>
#include <string>
#include <bitset>
#include "Localizing.h"

using namespace std;

// determines which child the fingerprint should be added to
// based on the first bit of the fingerprint
// returns 0 if should be added to left child, 1 if added to right child
int Localize::get_location(string fgpt, int currLevel) {
    return int(bitset<8>(fgpt[currLevel])[0]);
}

// recovers fingerprint from position in the LDCF tree structure
void Localize::recover_xi_x(string &str, CuckooFilter* node) {
    // not used explicitly, but used to create other functions
    string up_tree = "";
    CuckooFilter* parent = node->get_parent();
    while (parent != nullptr) {
        if (node == parent->get_left_child()) {
            up_tree = '0' + up_tree;
        }
        else if (node == parent->get_right_child()) {
            up_tree = '1' + up_tree;
        }
        node = parent;
        parent = parent->get_parent();
    }
    str.insert(0, up_tree);
    return;
}