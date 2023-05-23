// code by Fran

// logic behind defined functions

#include "cuckoofilter.h"
#include <iostream>

CuckooFilter::CuckooFilter(const size_t single_table_length) {
    this->single_table_length = single_table_length;

    bucket = new Bucket[single_table_length];
	for(size_t i = 0; i<single_table_length; i++){
        
		bucket[i].stored_kmer = 0;
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
    std::cout << endl;
}

// temporary insert function, needs to calculate hash with hash generating functions
void CuckooFilter::insert(size_t index,  int32_t value) {
    if (index >= single_table_length) {
        std::cout << "Invalid index. Insertion failed." << std::endl;
        return;
    }

    bucket[index].stored_kmer = value;
}

// temporary delete function , needs to delete as mentioned in header file , should be returning boolean value
void CuckooFilter::deleteItem(size_t index, int32_t value) {
    if (index >= single_table_length) {
        std::cout << "Invalid index. Deletion failed." << std::endl;
        return;
    }

    if (bucket[index].stored_kmer == value) {
        bucket[index].stored_kmer = 0;  // Empty the stored value
        std::cout << "Item at index " << index << " deleted." << std::endl;
    } else {
        std::cout << "Item at index " << index << " does not match the provided value. Deletion failed." << std::endl;
    }
}

// temporary query function , needs also to be refractored
bool CuckooFilter::query(size_t index, int32_t  value){
    if (index >= single_table_length) {
        std::cout << "Invalid index. Query failed." << std::endl;
        return false;
    }

    if (bucket[index].stored_kmer == value) {
        return true;
    }
    else return false;
}


int32_t CuckooFilter::generateFirstIndex(int32_t value, size_t single_table_length){

	int32_t index;

    index = value % single_table_length;

    return index;
	
}

int32_t CuckooFilter::generateSecondIndex(int32_t value, int32_t fingerprint, size_t single_table_length){ // for now, fingerprint is a fixed inserted value

    int32_t index;

    index = (value + fingerprint) % single_table_length;

    return index;
}

