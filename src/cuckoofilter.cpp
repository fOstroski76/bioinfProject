// code by Fran

#include "cuckoofilter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Hashing.h"
#include "HashNumber.h"
#include "selectvictim.h"

using namespace std;

// Cuckoo filter object class. Represents one cuckoo filter, which is one node in the LDCF cuckoo filters tree. Each Cuckoo Filter
// is determined by its' table length, bucket size, and current level (in the tree). Capacity of single cuckoo filter is the
// product of table length (number of buckets) and bucket size (number of elements per bucket)
CuckooFilter::CuckooFilter(int singleTableLength, int bucketSize, int currLevel) {

    single_table_length = singleTableLength;
    bucket_size = bucketSize;
    capacity = single_table_length * bucket_size;
    isEmpty = true;
    isFull = false;
    insertedCounter = 0;
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
    level = currLevel; 

    bucket = new Bucket[single_table_length];
	for(int i = 0; i<single_table_length; i++){
        
        for (int j = 0; j < bucket_size; j++){
            bucket[i].stored_kmer[j] = "";
        }
		
	}
    
}

// destructor 
CuckooFilter::~CuckooFilter() {
    
    delete[] bucket;
}

 // function to print all elements, used for small tests
string CuckooFilter::printContents() {
    string retVal = "";
    for (int i = 0; i < single_table_length; i++) {
    
        retVal += "Bucket " + to_string(i) + " :";
        for (int j = 0; j < bucket_size; j++){
           
           retVal += "  " + (bucket[i].stored_kmer[j]);
        }
        
        retVal += "\n";
    }

    retVal += "\n";
    return retVal;
}

// Tries to insert element  to its' supposed-to-be location, or to the alternative location. 
// Returns true if found on any of those locations, otherwise returns false.
bool CuckooFilter::insert(string value) {

    
    int index;
    int alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    for (int j = 0; j < bucket_size; j++){
    
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
 
    for (int j = 0; j < bucket_size; j++){

        if (bucket[alt_index].stored_kmer[j] == "") {  // second calculated position is empty
        
            bucket[alt_index].stored_kmer[j] = value;
            isEmpty = false;
            insertedCounter += 1;

            if (insertedCounter == capacity && insertedCounter != 0){
                isFull = true;
            }

            return true;
        
        }

    } 
        
    
    return false;
      
}

// Tries to delete element  from its' supposed-to-be location, or from the alternative location. 
// Returns true if found on any of those locations, otherwise returns false.
bool CuckooFilter::deleteItem(string value) {
    
    int index;
    int alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    for (int j = 0; j < bucket_size; j++){

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

    for (int j = 0; j < bucket_size; j++){
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
      
    return false;
}

// Checks whether the element is at its' supposed-to-be location, or at the alternative location. 
// Returns true if found on any of those locations, otherwise returns false.
bool CuckooFilter::query(string  value){
    
    int index;
    int alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    index = generateFirstIndex(value, single_table_length);
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    for (int j = 0; j < bucket_size; j++){
        if (bucket[index].stored_kmer[j] == value) {
        return true;    // if the value is at the first location, return true
        }
    }

    for (int j = 0; j < bucket_size; j++){
        if(bucket[alt_index].stored_kmer[j] == value) {
        return true;    // if the value is at the alternative location, return true
        }
    }
    
    return false;
}

// generates the first , a.k.a the original index where the value should be placed, using its' generated hash value.
// modulo operation with the number of buckets is performed so that the index is not out of bounds
uint32_t CuckooFilter::generateFirstIndex(string value, int singleTableLength){

	uint32_t index;
    Hashing hashing;
    HashNumber hn;

    string hashFromValue = hashing.hash_f(value);

    uint64_t hashAsNumber = hn.hash_to_number(hashFromValue);

    uint64_t tmp = 9;
    uint64_t tmp2 = 4;
    uint64_t tmp3 = tmp % tmp2;

    index = uint64_t(hashAsNumber) % uint64_t(singleTableLength);

    return index;
	
}

// generates the index for the alternative location of an input value, by using the value, its' fingerprint, and performs
// modulo with the table length (number of buckets per cuckoo filter) to make sure that the index is not out of bounds
uint32_t CuckooFilter::generateSecondIndex(string value, string fingerprint, int singleTableLength){ 

    uint32_t index;
    uint32_t alt_index;

    Hashing hashing;
    HashNumber hn;

    string hashFromValue = hashing.hash_f(value);
    int64_t fingerprintAsNumber = hn.hash_to_number(fingerprint);

    uint64_t hashAsNumber = hn.hash_to_number(hashFromValue);

    index = hashAsNumber % singleTableLength;
    
    alt_index = uint32_t(index ^ (fingerprintAsNumber * 0x9e3779b9)) % singleTableLength; // golden ratio constant to enforce randomness
    
    return alt_index;
}

// Tries to insert input value (k-mer) into a current cuckoo filter. Calls insert() function that tries to place the value
// in its' supposed-to-be location (from hash) or its' first alternative. If that insertion fails, a victim is randomly selected
// and value is replaced with the victim, and the victim goes into the next iteration. '
// Returns "true" if successful, returns "false" if the max relocation (kick) limit is reached (500)
bool CuckooFilter::tryInsert(string value){

    for(int i = 0; i < MAX_RELOCATION; i++){
        if(insert(value)) {
            
            return true;
        }

        else {
    
            Hashing hashing;
            VictimGenerator vg;
            int victimIndex = vg.selectVictim(bucket_size);
            string valueFingerprint = hashing.fingerprint(value);
            int32_t valueFirstIndex = generateFirstIndex(value,single_table_length);
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

int CuckooFilter::get_single_table_length() {
    return single_table_length;
}

int CuckooFilter::get_bucket_size() {
    return bucket_size;
}

int CuckooFilter::get_level() {
    return level;
}

bool CuckooFilter::generate_children(int singleTableLength, int bucketSize, int currLevel) {
    // cout << "ulazim u generiranje djece s bucket sizeom" << bucketSize << endl;
    right_child = new CuckooFilter(singleTableLength, bucketSize, currLevel + 1);
    // cout << right_child->get_bucket_size() << endl;
    right_child->parent = this;
    left_child = new CuckooFilter(single_table_length, bucket_size, currLevel + 1);
    left_child->parent = this;
    return true;
}


string CuckooFilter::CF_string() {
    stringstream ss;
    ss << "CF: empty=" << this->isEmpty << ", full=" << this->isFull << endl;
    ss << "\t left_child = " << get_left_child() << ", right_child = " << get_right_child() << endl;
    ss << "\t node content: " << endl << printContents();
    if (get_left_child() != nullptr) {
        ss << "\t left_child: \n";
        ss << get_left_child()->printContents();
    }
    if (get_right_child() != nullptr) {
        ss << "\t right_child: \n";
        ss << get_right_child()->printContents();
    }
    return ss.str();
}