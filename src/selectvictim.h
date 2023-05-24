// code written by Fran

#ifndef SELECTVICTIM_H
#define SELECTVICTIM_H

#include <random>

class VictimGenerator {

    public:

    int selectVictim(size_t bucket_size); // generates a random number from [0, bucket_size-1] to represent index of the victim
};

#endif // SELECTVICTIM_H
