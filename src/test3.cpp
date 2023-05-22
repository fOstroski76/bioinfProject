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

    cout << endl;
    cout << "After inserts:" << endl;

    filter.printContents();

    filter.deleteItem(3,"ATAT");
    filter.deleteItem(1,"CGTA");

    cout << endl;
    cout << "After deletions:" << endl;

    filter.printContents();

    if(filter.query(7,"GTCA")) {
        cout << "Element is present" << endl;
    }
    // Rest of your code

    return 0;
}