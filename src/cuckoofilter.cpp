// code by Fran

// logic behind defined functions

#include "CuckooFilter.h"
#include <iostream>

CuckooFilter::CuckooFilter(const size_t single_table_length) {
    this->single_table_length = single_table_length;

    bucket = new Bucket[single_table_length];
	for(size_t i = 0; i<single_table_length; i++){
        string empty = "";
		bucket[i].stored_kmer = empty;
        //memset(bucket[i].stored_kmer, 0, sizeof(string));
	}
    
}

// destructor 
CuckooFilter::~CuckooFilter() {
    
    delete[] bucket;
}

 // function to print all elements, used for small tests
void CuckooFilter::printContents() {
    for (size_t i = 0; i < single_table_length; i++) {
        std::cout << "Bucket " << i << " - stored_kmer: " << (bucket[i].stored_kmer) << std::endl;
    }
}

// temporary insert function, needs to calculate hash with hash generating functions
void CuckooFilter::insert(size_t index,  std::string value) {
    if (index >= single_table_length) {
        std::cout << "Invalid index. Insertion failed." << std::endl;
        return;
    }

    bucket[index].stored_kmer = value;
}






