// code written by Elena

#include <iostream>
#include <string>
#include <bitset>
#include "Localizing.h"
// #include "CF.h"

using namespace std;

int Localize::get_location(string fgpt, int currLevel) {
    // cout << "string = " << str << endl;
    // cout << bitset<8>(str[0]) << endl;

    // testing...
    // for (int i = 0; i < 8; i++) {
    //     cout << bitset<8>(str[0])[i];
    // }
    // cout << endl;
    // conclusion: it is reversed!

    // cout << bitset<8>(str[0])[0] << endl;

    // fgpt.erase(0, 1);

    return int(bitset<8>(fgpt[currLevel])[0]);
}

void Localize::recover_xi_x(string &str, CuckooFilter* node) {
    // not properly working but pushed so other can work with other code
    string up_tree = "";
    CuckooFilter* parent = node->get_parent();
    // cout << "ulazni node je " << node << endl;
    // cout << "ulazni parent je " << parent << endl;
    while (parent != nullptr) {
        if (node == parent->get_left_child()) {
            up_tree = '0' + up_tree;
            // cout << "adding 0" << endl;
        }
        else if (node == parent->get_right_child()) {
            up_tree = '1' + up_tree;
            // cout << "adding 1" << endl;
        }
        else {
            // cout << "nesto je krivo!" << endl;
        }
        node = parent;
        // cout << "node je sada " << &node << endl;
        parent = parent->get_parent();
        // cout << "parent je sada " << &parent << endl;
    }
    // cout << "up_tree: " << up_tree << endl;
    str.insert(0, up_tree);
    // cout << "whole fingerprint is: " << str << endl;
    return;
}