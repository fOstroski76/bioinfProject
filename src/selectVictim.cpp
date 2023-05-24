// code written by Fran

#include "selectvictim.h"

// function generates a random number from interval [0, bucket_size - 1]
int VictimGenerator::selectVictim(size_t bucket_size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, bucket_size - 1);
    return dis(gen);
}