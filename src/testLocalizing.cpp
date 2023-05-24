// code written by Elena

#include <iostream>
#include <string>
#include "Localizing.h"

using namespace std;

int main() {
    Localize loc;

    string str = "ATGCGNCGCGNCGTANTGNTGAGC";        
    int index = loc.get_location(str);
    // cout << "lokacija = " << index << endl;
    // cout << "str = " << str << endl;

    str = "BBGCGNCGCGNCGTANTGNTGAGC";        
    index = loc.get_location(str);
    // cout << "lokacija = " << index << endl;
    // cout << "str = " << str << endl;      
    return 0;
}