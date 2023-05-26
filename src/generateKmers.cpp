// written by Fran

// code that generates k-mers to be filtered with the cuckoo filter

#include <iostream>
#include <string>
#include <vector>
#include "generatekmers_h" 

using namespace std;

    // implementation of generate_kmers function
    // function accepts the desired input string and produces M - K + 1 k-mers, where M is the length of the string
    // k-kmers are stored in a vector   
    vector<string> kmerGenFunc :: generate_kmers(const std::string& input_string, int k) {
    std::vector<std::string> kmers;
    for (int i = 0; i <= input_string.length() - k; i++) {
        std::string kmer = input_string.substr(i, k);
        kmers.push_back(kmer);
    }
    return kmers;
}

