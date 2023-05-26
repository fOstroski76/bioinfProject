// code written by Fran

#include <iostream>
#include <stdlib.h>     // rand, rand
#include <time.h>       // time
#include <stdlib.h>     // srand, rand
#include "selectvictim.h"
using namespace std;

// function generates a random number from interval [0, bucket_size - 1]
int VictimGenerator::selectVictim(int bucket_size) {
    // cout << "ulazak u selectVictim" << endl;
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // cout << "victim 1, gen = " << gen << endl;
    // std::uniform_int_distribution<> dis(0, bucket_size - 1);
    // cout << "victim 2" << endl;
    // int retVal = dis(gen);
    // cout << "victim 3" << endl;
    // return dis(gen);
    
    // code written by Elena

    srand(time(NULL));
    cout << "bucket_size = " << bucket_size << endl;

    return (rand() % bucket_size);
}