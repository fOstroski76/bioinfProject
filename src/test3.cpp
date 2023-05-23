// code by Fran

// program for testing purposes

// to run, use:
// g++ test3.cpp  cuckoofilter.cpp Hashing.cpp -o test3 -lssl -lcrypto 

#include <iostream>
#include "cuckoofilter.h"
#include "hashing.h"


using namespace std;

int main() {
    size_t tableLength;
    std::cout << "Enter the table length for the CF: ";
    std::cin >> tableLength;

    CuckooFilter filter(tableLength);
    cout << "At the beginning:" << endl;

    filter.printContents();
    
    filter.insert(120);
    filter.insert(456);
    filter.insert(789);
    filter.insert(720);
    filter.insert(880);

    cout << endl;
    cout << "After inserts:" << endl;

    filter.printContents();

    filter.deleteItem(789);
    //filter.deleteItem(720);

    cout << endl;
    cout << "After deletions:" << endl;

    filter.printContents();

    if(filter.query(720)) {
        cout << "Element is present" << endl;
    } else {
        cout << "Element is not present" << endl;
    }
    
    cout << filter.generateFirstIndex(123,tableLength) << endl;
    cout << filter.generateSecondIndex(123,3,tableLength) << endl;

    return 0;
}