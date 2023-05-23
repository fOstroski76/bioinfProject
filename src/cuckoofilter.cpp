// code by Fran

// logic behind defined functions

#include "cuckoofilter.h"
#include <iostream>
#include "Hashing.h"

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
void CuckooFilter::insert( int32_t value) {

    size_t index;
    size_t alt_index;
    
    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, 3, single_table_length);
    
    if (bucket[index].stored_kmer == 0) {  // first calculated position is empty
        bucket[index].stored_kmer = value;

    } else if (bucket[alt_index].stored_kmer == 0){ // second calculated position is empty
        bucket[alt_index].stored_kmer = value;
    } else {  // both values occupied , TU VICTIM DOLAZI, SLOŽI KASNIJE!!
        cout << "Insert failed! Both locations occupied!" << endl;
    }
    
}

// temporary delete function , needs to delete as mentioned in header file , should be returning boolean value
void CuckooFilter::deleteItem( int32_t value) {
    
    size_t index;
    size_t alt_index;

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, 3, single_table_length);

    if (bucket[index].stored_kmer == value) {
        bucket[index].stored_kmer = 0;  // Empty the stored value
        std::cout << "Item at index " << index << " deleted." << std::endl;

    } else if (bucket[alt_index].stored_kmer == value){ // Check the alternate location and empty it
        bucket[alt_index].stored_kmer = 0;  
        std::cout << "Item " << value << " was at index " << alt_index << " instead of original " << index << ". Item deleted." << std::endl;
    } else {
        std::cout <<  "Deletion failed. Element wasnt in any of two locations." << std::endl;
    }
}

// temporary query function , needs also to be refractored
bool CuckooFilter::query(int32_t  value){
    
    size_t index;
    size_t alt_index;

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, 3, single_table_length);

    if (bucket[index].stored_kmer == value) {
        return true;    // if the value is at the first location, return true
    }
    else if(bucket[alt_index].stored_kmer == value) {
        return true;    // if the value is at the alternative location, return true
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

