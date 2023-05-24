// code by Fran

// program for testing purposes

// to run, use:
// g++ test3.cpp  cuckoofilter.cpp Hashing.cpp -o test3 -lssl -lcrypto 

#include <iostream>
#include "cuckoofilter.h"
#include "hashing.h"
#include "HashNumber.h"
#include "selectvictim.h"



using namespace std;

int main() {
    size_t tableLength;
    std::cout << "Enter the table length for the CF: ";
    std::cin >> tableLength;

    CuckooFilter filter(tableLength);
    cout << "At the beginning:" << endl;

    filter.printContents();
    
    filter.insert("ACTGA");
    filter.insert("TCCTA");
    filter.insert("GGGTG");
    filter.insert("CTATT");
    filter.insert("AACAA");
    filter.insert("ATCGG");
    filter.insert("GACTG");
    filter.insert("GCAAC");
    filter.insert("TCATT");
    filter.insert("TGAGT");
    filter.insert("TGAGG");
    filter.insert("GTGAA");
    filter.insert("AAAAA");
    filter.insert("TTTTT");
    filter.insert("CCCCC");
    filter.insert("AACCA");
    filter.insert("TGTTT");
    filter.insert("TATAT");
    filter.insert("AGAGA");
    filter.insert("AACAA");
    filter.tryInsert("AACAA");
    filter.tryInsert("AACAA");

    cout << endl;
    cout << "After inserts:" << endl;

    filter.printContents();

    filter.deleteItem("TCATT");
    filter.deleteItem("GCAAC");

    cout << endl;
    cout << "After deletions:" << endl;

    filter.printContents();

    
    if(filter.query("ACTGA")) {
        cout << "Element is present" << endl;
    } else {
        cout << "Element is not present" << endl;
    }
    
    
    //cout << filter.generateFirstIndex(123,tableLength) << endl;
    //cout << filter.generateSecondIndex(123,3,tableLength) << endl;

    HashNumber hNum;
    Hashing hashing;

    cout << "Hash testing:" << endl;

    string niz = "ACTGA";
    uint64_t hashNizaKoBroj = hNum.hash_to_number(niz);
    cout << hashNizaKoBroj << endl;
    string opetHash = hNum.number_to_hash(hashNizaKoBroj,6);

    cout << opetHash << endl;

    string niz2 = "ACTGA";

    string mu_x = hashing.hash_f(niz);
    cout << "mu_x = " << mu_x << endl;

    filter.insert("ACTGA");

    cout << "Victim gen test:" << endl;

    VictimGenerator vg;

    for (int i = 0; i< 5; i++){
        int victimIndex = vg.selectVictim();

        cout << " " << victimIndex;
    }
    

    return 0;
}