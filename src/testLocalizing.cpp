// code written by Elena

#include <iostream>
#include <string>
#include "Localizing.h"

using namespace std;

int main() {
    Localize loc;

    string str = "ATGCGNCGCGNCGTANTGNTGAGC";        
    int index = loc.get_location(str);
    cout << "lokacija = " << index << endl;

    str = "BTGCGNCGCGNCGTANTGNTGAGC";        
    index = loc.get_location(str);
    cout << "lokacija = " << index << endl;       
    return 0;
}