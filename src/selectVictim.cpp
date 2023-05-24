#include "selectvictim.h"


int VictimGenerator::selectVictim() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    return dis(gen);
}