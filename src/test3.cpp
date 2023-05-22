// code by Fran

// program for testing purposes

#include <iostream>
#include "cuckoofilter.h"

using namespace std;

int main() {
    size_t tableLength;
    std::cout << "Enter the table length for the CF: ";
    std::cin >> tableLength;

    CuckooFilter filter(tableLength);
    //cout << "At the beginning:" << endl;

    //filter.printContents();
    
    filter.insert(3,"ATAT");
    filter.insert(7,"GTCA");
    filter.insert(1,"CTCA");

    cout << "After inserts:" << endl;

    filter.printContents();
    // Rest of your code

    return 0;
}