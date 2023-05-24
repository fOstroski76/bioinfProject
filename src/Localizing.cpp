// code written by Elena

#include <iostream>
#include <string>
#include <bitset>
#include "Localizing.h"

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