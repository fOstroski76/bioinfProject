#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LDCF.h"

using namespace std;

std::vector<std::string> generate_kmers(const std::string& input_string, int k) {
    std::vector<std::string> kmers;
    int m = input_string.length();
    
    if (k > m) {
        return kmers;  // Return an empty vector if k is greater than the length of the input string
    }
    
    for (int i = 0; i <= m - k; i++) {
        std::string kmer = input_string.substr(i, k);
        kmers.push_back(kmer);
    }
    
    return kmers;
}


std::string get_from_file(std::string path){
    std::ifstream file(path);
    std::string output;

    if(file.is_open()){
        std::string line;

        while(std::getline(file, line)){
            output.append(line);
        }
        file.close();
        return output;
    } else {
        return " ";
    }
}

int main(){

    int k = 5;
    int tableLen = 16;
    int buckSize = 8; 

    LDCF* logDynCuckooFilter = new LDCF(100, 16, 8);

    CuckooFilter* node = logDynCuckooFilter->get_node();

    CuckooFilter* left_child = logDynCuckooFilter->get_left_child();
    
    CuckooFilter* right_child = logDynCuckooFilter->get_right_child(); 


    std::string path = "raw_input_100.txt"; 
    std::string content = get_from_file(path);
    
    std::string path_of_synthetic_inputs = "input_sythetic_100.txt";
    std::string syntheticContent = get_from_file(path_of_synthetic_inputs);


    std::vector<std::string> result = generate_kmers(content, k);
    std::vector<std::string> resultSynt = generate_kmers(syntheticContent, k);


    std::ofstream outputFile("Output.txt");

     if (outputFile.is_open()) {
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(outputFile.rdbuf());

        // Write output to the file
        for (const auto& kmer : result) {
            logDynCuckooFilter->insert(kmer);
        }

        cout << "Querying over same elements that were inserted..." << endl << endl;

        for (const auto& kmer : result) {
            if(logDynCuckooFilter->query(kmer)){
                cout << "K-mer: " << kmer << " found: yes" << endl; 
            } else {
                cout << "K-mer: " << kmer << " found: no" << endl; 
            }
        }

        std::cout << std::endl << endl;

        cout << "Querying randomly generated input..." << endl << endl;

        for (const auto& kmer : resultSynt) {
            if(logDynCuckooFilter->query(kmer)){
                cout << "K-mer: " << kmer << " found: yes" << endl; 
            } else {
                cout << "K-mer: " << kmer << " found: no" << endl; 
            }
        }

     }

    outputFile.close();


    return 0;
}