// code by Fran

// program for testing purposes

#include <iostream>
#include "cuckoofilter.h"
#include "hashing.h"


using namespace std;

int main() {
    size_t tableLength;
    std::cout << "Enter the table length for the CF: ";
    std::cin >> tableLength;

    CuckooFilter filter(tableLength);
    //cout << "At the beginning:" << endl;

    //filter.printContents();
    
    filter.insert(3,123);
    filter.insert(7,456);
    filter.insert(1,789);

    cout << endl;
    cout << "After inserts:" << endl;

    filter.printContents();

    filter.deleteItem(3,123);
    filter.deleteItem(1,654);

    cout << endl;
    cout << "After deletions:" << endl;

    filter.printContents();

    if(filter.query(7,6)) {
        cout << "Element is present" << endl;
    } else {
        cout << "Element is not present" << endl;
    }
    
    cout << filter.generateFirstIndex(123,tableLength) << endl;
    cout << filter.generateSecondIndex(123,3,tableLength) << endl;

    return 0;
}