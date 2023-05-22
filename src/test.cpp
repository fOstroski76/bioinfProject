// code written by Fran

// temporary testing code to test functionality of "generateKmers" code 

#include <iostream>
#include <string>
#include <vector>
#include "generatekmers_h"

int main() {
    std::string input_string = "ATCGGCTA";
    int k = 3;

    std::vector<std::string> kmers = kmerGenFunc::generate_kmers(input_string, k);

    std::cout << "Generated kmers:" << std::endl;
    for (const auto& kmer : kmers) {
        std::cout << kmer << std::endl;
    }

    return 0;
}



