// code written by Elena

#include <iostream>
#include <string>
#include <bitset>
#include "Localizing.h"
// #include "CF.h"

using namespace std;

int Localize::get_location(string &str) {
    // cout << "string = " << str << endl;
    // cout << bitset<8>(str[0]) << endl;

    // testing...
    // for (int i = 0; i < 8; i++) {
    //     cout << bitset<8>(str[0])[i];
    // }
    // cout << endl;
    // conclusion: it is reversed!

    // cout << bitset<8>(str[0])[0] << endl;

    str.erase(0, 1);

    return int(bitset<8>(str[0])[0]);
}

void Localize::recover_xi_x(string &str, CF* node) {
    // not properly working but pushed so other can work with other code
    string up_tree = "";
    CF* parent = node->get_parent();
    while (parent != nullptr) {
        if (node == node->get_left_child()) {
            up_tree += '0';
        }
        else {
            up_tree += '1';
        }
        parent = parent->get_parent();
    }
    str.insert(0, up_tree);
    cout << str << endl;
    return;
}