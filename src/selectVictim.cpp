// code written by Fran

#include <iostream>
#include <stdlib.h>     // rand, rand
#include <time.h>       // time
#include <stdlib.h>     // srand, rand
#include "selectvictim.h"
using namespace std;

// function generates a random number from interval [0, bucket_size - 1]
int VictimGenerator::selectVictim(int bucket_size) {
   
    srand(time(NULL));

    return (rand() % bucket_size);
}