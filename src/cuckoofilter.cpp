// code by Fran

// logic behind defined functions

#include "cuckoofilter.h"
#include <iostream>
#include "Hashing.h"
#include "HashNumber.h"
#include <algorithm>

using namespace std;

CuckooFilter::CuckooFilter(const size_t single_table_length) {
    this->single_table_length = single_table_length;

    bucket = new Bucket[single_table_length];
	for(size_t i = 0; i<single_table_length; i++){
        
        for (size_t j = 0; j < 4; j++){
            bucket[i].stored_kmer[j] = "";
        }
		
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
        std::cout << "Bucket " << i << " : ";
        for (size_t j = 0; j < 4; j++){
           std::cout << "  " << (bucket[i].stored_kmer[j]);
        }
        std::cout << endl;
    }
    std::cout << endl;
}

// temporary insert function, needs to calculate hash with hash generating functions
bool CuckooFilter::insert( string value) {

    size_t index;
    size_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);
    
    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);
    
    for (size_t j = 0; j < 4; j++){
        if (bucket[index].stored_kmer[j] == "") {  // first calculated position is empty
        bucket[index].stored_kmer[j] = value;
        return true;
        }
    }
    
    for (size_t j = 0; j < 4; j++){

        if (bucket[alt_index].stored_kmer[j] == "") {  // second calculated position is empty
        bucket[alt_index].stored_kmer[j] = value;
        //cout << value << " je bio bouncan alternativno!" << endl;
        return true;
        }

    } 
        
    cout << "Insert failed! Both locations occupied!" << endl;
    return false;
    
    
}

// temporary delete function , needs to delete as mentioned in header file , should be returning boolean value
bool CuckooFilter::deleteItem( string value) {
    
    size_t index;
    size_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    for (size_t j = 0; j < 4; j++){

        if (bucket[index].stored_kmer[j] == value) {
        bucket[index].stored_kmer[j] = "";  // Empty the stored value
        std::cout << "Item " << value << " at index " << index << " deleted." << std::endl;
        return true;
        }
        
    }

    for (size_t j = 0; j < 4; j++){
        if (bucket[alt_index].stored_kmer[j] == value){ // Check the alternate location and empty it
        bucket[alt_index].stored_kmer[j] = "";  
        std::cout << "Item " << value << " was at index " << alt_index << " instead of original " << index << ". Item deleted." << std::endl;
        return true;
        }
        
    }
      
    std::cout <<  "Deletion failed. Element wasnt in any of two locations." << std::endl;
    return false;
}

// temporary query function , needs also to be refractored
bool CuckooFilter::query(string  value){
    
    size_t index;
    size_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    for (size_t j = 0; j < 4; j++){
        if (bucket[index].stored_kmer[j] == value) {
        return true;    // if the value is at the first location, return true
        }
    }

    for (size_t j = 0; j < 4; j++){
        if(bucket[alt_index].stored_kmer[j] == value) {
        return true;    // if the value is at the alternative location, return true
        }
    }
    
    return false;
}


int32_t CuckooFilter::generateFirstIndex(string value, size_t single_table_length){

	int32_t index;
    Hashing hashing;
    HashNumber hn;

    string hashFromValue = hashing.hash_f(value);

    int64_t hashAsNumber = hn.hash_to_number(hashFromValue);

    index = hashAsNumber % single_table_length;

    return index;
	
}

int32_t CuckooFilter::generateSecondIndex(string value, string fingerprint, size_t single_table_length){ // for now, fingerprint is a fixed inserted value

    int32_t index;
    int32_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string hashFromValue = hashing.hash_f(value);
    int64_t fingerprintAsNumber = hn.hash_to_number(fingerprint);

    int64_t hashAsNumber = hn.hash_to_number(hashFromValue);

    index = hashAsNumber % single_table_length;

    alt_index = (index ^ (fingerprintAsNumber * 0x9e3779b9)) % single_table_length; // golden ratio constant to enforce randomness

    return alt_index;
}

