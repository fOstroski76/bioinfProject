// code written by Fran

// temporary testing code to test functionality of "generateKmers" code 


//  g++ test.cpp  cuckoofilter.cpp Hashing.cpp generateKmers.cpp HashNumber.cpp SelectVictim.cpp -o test -lssl -lcrypto

#include <iostream>
#include <string>
#include <vector>
#include "generatekmers_h"
#include "cuckoofilter.h"
#include "Hashing.h"

int main() {
    std::string input_string = "AGCCCAAGCGCGGAACGGATGCGATCGGGCACAATGTCCTTGCCGTCCTTCCGGTAAATGAAGTTCAGCAGGTCAATCTCCCACAACGGGCGATCGTTAA";
    std::string input_string2 = "AGCCCAAGCGCGGAACGGATGCGATCGGGCACAATGTCCTTGCCGTCCTTCCGGTAAATGAAGTTCAGCAGGTCAATCTCCCACAACGGGCGATCGTTAACGCTCAGCTTGTAGTAGGTGTTTTTAATGGCGTAAGTGTGTGATGTGGCTTCGCCCTGTTTGGCTTCCCCCATATCAATTTCCGTCACACGTCCGCGCATTTCGACTTCATACAGGTCGCTTTCTGCATCGGTGTAGTATTCACCCGCAAAACGCAGCAGCGTGCCGTCAATCGTGCCGCCATACTTAAGGAACAGCTCACGAACTGCGCCCCCCATGACAAAGCTCGCATCAAGCGCGGAGTCGTCCAGACCGAGATCAATACTTACTGCCCCCATCATGCCACCACCCCGGTAGCTGTCGGTTTTGCGCGTCAGCTTAGGCAGAGTGACGGATGTCACTTTACCCACTTCGTTTTCACCATCCACAAACAACGTAAAAAAGCGAAGATGTTTTGGTACAGCCATCAGGCACCTCCCAGCACCGCAAATGCGGGACCAAAGAATTCATCAGTAAACGTCTGGTAAAGCTCCATGTCTTCCAGCGGGGGAACGGGCGTATATTTGTAGCGAATACGCACACGCCCCTGACGTAAATCCGTGGTGCCGTTATCCACCACGTCATACCAGCACTCCGCGCCAATCAGTTTCCCGGCAGTAACCAGCGAATCCAGTTTTGCCCTGATGGCGCTGATAACATCCTTCACGTTCGCAGGCGTCAGTGGACTGTCGATGGTTTCAAACTGCGCTTCCGCAATTGAATCAGCCAGCACCTGTGCGGTTCGGGTATACACCTCAAAGATGTAGGCGTTCGTTTCCGGTGTGCGGTTGCCCCAGAAGCGGAACCCGTTGCGACGAATAATGGTCGTGATTTCTTTGTTGTTGAGGCTGTTGGCATCGCTGTCTTCGGCCTGCAACGACCAGAACACATGCCTCGACATCCCCAGCACATTTTTAACCGGAACGTTGGACAGTGATTTGT";
    Hashing hashing;
    int k = 10;
    string fgpt;
    
    CuckooFilter filter = CuckooFilter(12,8,0);

    std::vector<std::string> kmers = kmerGenFunc::generate_kmers(input_string, k);
    int kmerCounter = 0;

    for(const auto& kmer : kmers){
        kmerCounter++;
    }

    std::cout << "Generated kmers:" << std::endl;
    for (const auto& kmer : kmers) {
        //std::cout << kmer << std::endl;
        
        if(!filter.isFull) {
            
            //fgpt = hashing.fingerprint(kmer);
            filter.tryInsert(kmer);
        }
        else{
            break;
        }
    }

    float percentage = static_cast<float>(filter.insertedCounter) / static_cast<float>(filter.capacity);
    cout << filter.printContents();
    cout << "Slots filled:" << filter.insertedCounter << " / " << filter.capacity << "  (" << percentage * 100 << "%)" <<  " Kmer count:" << kmerCounter <<endl;

    cout << "Query results:" << endl;

    int yes = 0;
    int no = 0;
    for (const auto& kmer : kmers) {
        
        //std::cout << kmer << std::endl;
        if(filter.query(kmer)){
            yes++;
        }  else {
            no++;
        }  
    
    }

    cout << "Yes: " << yes << "  No: " << no << endl;
    return 0;
}



