// code written by Fran

// temporary testing code to test functionality of "generateKmers" code 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "generatekmers_h"

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file. " << std::endl;
        return 1;
    }

    std::string input_string;
    int k;

    if (!(inputFile >> input_string >> k)) {
        std::cerr << "Failed to read input from file. " << std::endl;
        return 1;
    }

    inputFile.close();

    std::vector<std::string> kmers = kmerGenFunc::generate_kmers(input_string, k);

    std::cout << "Generated kmers:" << std::endl;
    for (const auto& kmer : kmers) {
        std::cout << kmer << std::endl;
    }

    return 0;
}
