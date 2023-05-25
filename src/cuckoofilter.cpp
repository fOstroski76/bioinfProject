// code by Fran

// logic behind defined functions

#include "cuckoofilter.h"
#include <iostream>
#include "Hashing.h"
#include "HashNumber.h"
#include <algorithm>
#include "selectvictim.h"

using namespace std;

CuckooFilter::CuckooFilter(const size_t single_table_length, const size_t bucket_size, int curr_level) {

    this->single_table_length = single_table_length;
    this->bucket_size = bucket_size;
    capacity = single_table_length * bucket_size;
    isEmpty = true;
    isFull = false;
    // cout << "in CF constructor -> setting isFull to false" << endl;
    insertedCounter = 0;
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
    level = curr_level; 

    bucket = new Bucket[single_table_length];
	for(size_t i = 0; i<single_table_length; i++){
        
        for (size_t j = 0; j < bucket_size; j++){
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
        for (size_t j = 0; j < bucket_size; j++){
           std::cout << "  " << (bucket[i].stored_kmer[j]);
        }
        std::cout << endl;
    }
    std::cout << endl;
}

// temporary insert function
bool CuckooFilter::insert( string value) {

    size_t index;
    size_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);
    
    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);
    
    for (size_t j = 0; j < bucket_size; j++){
        if (bucket[index].stored_kmer[j] == "") {  // first calculated position is empty
        bucket[index].stored_kmer[j] = value;
        isEmpty = false;
        insertedCounter += 1;

        if (insertedCounter == capacity && insertedCounter != 0){
            isFull = true;
        }
        return true;
        }
    }
    
    for (size_t j = 0; j < bucket_size; j++){

        if (bucket[alt_index].stored_kmer[j] == "") {  // second calculated position is empty
        bucket[alt_index].stored_kmer[j] = value;
        //cout << value << " je bio bouncan alternativno!" << endl;
        isEmpty = false;
        insertedCounter += 1;

        if (insertedCounter == capacity && insertedCounter != 0){
            isFull = true;
        }

        return true;
        
        }

    } 
        
    //cout << "Insert failed! Both locations occupied!" << endl;
    return false;
    
    
}

// temporary delete function 
bool CuckooFilter::deleteItem( string value) {
    
    size_t index;
    size_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    for (size_t j = 0; j < bucket_size; j++){

        if (bucket[index].stored_kmer[j] == value) {
        bucket[index].stored_kmer[j] = "";  // Empty the stored value
        std::cout << "Item " << value << " at index " << index << " deleted." << std::endl;

        insertedCounter -= 1;
        if (insertedCounter == 0){
            isEmpty = true;
        }

        if (insertedCounter < capacity) {
            isFull = false;
        }
        return true;
        }
        
    }

    for (size_t j = 0; j < bucket_size; j++){
        if (bucket[alt_index].stored_kmer[j] == value){ // Check the alternate location and empty it
        bucket[alt_index].stored_kmer[j] = "";  
        std::cout << "Item " << value << " was at index " << alt_index << " instead of original " << index << ". Item deleted." << std::endl;

        insertedCounter -= 1;
        if (insertedCounter == 0){
            isEmpty = true;
        }

        if (insertedCounter < capacity) {
            isFull = false;
        }

        return true;
        }
        
    }
      
    //std::cout <<  "Deletion failed. Element wasnt in any of two locations." << std::endl;
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

    for (size_t j = 0; j < bucket_size; j++){
        if (bucket[index].stored_kmer[j] == value) {
        return true;    // if the value is at the first location, return true
        }
    }

    for (size_t j = 0; j < bucket_size; j++){
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


bool CuckooFilter::tryInsert(string value){

    for(size_t i = 0; i < MAX_RELOCATION; i++){
        if(insert(value)) {
            return true;
        }

        else {
            Hashing hashing;
            VictimGenerator vg;
            int victimIndex = vg.selectVictim(bucket_size);
            string valueFingerprint = hashing.fingerprint(value);
            int32_t valueFirstIndex = generateFirstIndex(value,single_table_length);
            //int32_t valueSecondIndex = generateSecondIndex(value,valueFingerprint, single_table_length);
            string victim = bucket[valueFirstIndex].stored_kmer[victimIndex];
            bucket[valueFirstIndex].stored_kmer[victimIndex] = value;
            value = victim;
            
        }
    }
    isFull = true;
    return false;
}

// code written by Elena

CuckooFilter* CuckooFilter::get_right_child() {
    return right_child;
}

CuckooFilter* CuckooFilter::get_left_child() {
    return left_child;
}

CuckooFilter* CuckooFilter::get_parent() {
    return parent;
}

size_t CuckooFilter::get_single_table_length() {
    return single_table_length;
}

size_t CuckooFilter::get_bucket_size() {
    return bucket_size;
}

bool CuckooFilter::generate_children(const size_t single_table_length, const size_t bucket_size, int curlevel) {
    right_child = new CuckooFilter(single_table_length, bucket_size, curlevel + 1);
    right_child->parent = this;
    left_child = new CuckooFilter(single_table_length, bucket_size, curlevel + 1);
    left_child->parent = this;
    return true;
}


string CuckooFilter::CF_string() {
    stringstream ss;
    ss << "CF: empty=" << this->isEmpty << ", full=" << this->isFull << endl;
    ss << "\t left_child = " << get_left_child() << ", right_child = " << get_right_child() << endl;
    return ss.str();
}