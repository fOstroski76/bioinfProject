// code by Fran

// logic behind defined functions

#include "cuckoofilter.h"
#include <iostream>
#include "Hashing.h"
#include "HashNumber.h"
#include <algorithm>
#include "selectvictim.h"

using namespace std;

CuckooFilter::CuckooFilter(int singleTableLength, int bucketSize, int currLevel) {

    single_table_length = singleTableLength;
    cout << "single_table_length has been set to: " << single_table_length << endl;
    bucket_size = bucketSize;
    capacity = single_table_length * bucket_size;
    isEmpty = true;
    isFull = false;
    // cout << "in CF constructor -> setting isFull to false" << endl;
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
		
        //memset(bucket[i].stored_kmer, 0, sizeof(string));
	}
    cout << "izlazim iz constructora i trenutno je stl " << single_table_length << endl;
    
}

// destructor 
CuckooFilter::~CuckooFilter() {
    
    delete[] bucket;
}

 // function to print all elements, used for small tests
void CuckooFilter::printContents() {
    for (int i = 0; i < single_table_length; i++) {
        std::cout << "Bucket " << i << " : ";
        for (int j = 0; j < bucket_size; j++){
           std::cout << "  " << (bucket[i].stored_kmer[j]);
        }
        std::cout << endl;
    }
    std::cout << endl;
}

// temporary insert function
bool CuckooFilter::insert(string value) {

    cout << "ušao sam u insert s bucket_sizeom veličine " << bucket_size << endl;

    int index;
    int alt_index;

    Hashing hashing;
    HashNumber hn;

    string fingerprint = hashing.fingerprint(value);

    cout << "ulazim u generateFirstIndex" << endl;
    index = generateFirstIndex(value, single_table_length);
    cout << "izašao sam iz generateFirstIndex" << endl;
    alt_index = generateSecondIndex(value, fingerprint, single_table_length);

    cout << "bucket size u fji insert = " << bucket_size << endl;
    for (int j = 0; j < bucket_size; j++){
        cout << index << endl;
        if (bucket[index].stored_kmer[j] == "") {  // first calculated position is empty
            cout << "prošao je if" << endl;
            bucket[index].stored_kmer[j] = value;
            isEmpty = false;
            insertedCounter += 1;

            if (insertedCounter == capacity && insertedCounter != 0){
                isFull = true;
            }
            return true;
        }
    }


    cout << "alt_index = " << alt_index << endl;
    auto bla = bucket[alt_index];

    cout << "bucket_size = " << bucket_size << endl;
    
    for (int j = 0; j < bucket_size; j++){
        cout << "here 1" << endl;

        if (bucket[alt_index].stored_kmer[j] == "") {  // second calculated position is empty
            cout << "here 2" << endl;
            bucket[alt_index].stored_kmer[j] = value;
            //cout << value << " je bio bouncan alternativno!" << endl;
            isEmpty = false;
            insertedCounter += 1;
            cout << "here 3" << endl;

            if (insertedCounter == capacity && insertedCounter != 0){
                isFull = true;
            }

            return true;
        
        }

    } 
        
    cout << "Insert failed! Both locations occupied!" << endl;
    return false;
    
    
}

// temporary delete function 
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
      
    //std::cout <<  "Deletion failed. Element wasnt in any of two locations." << std::endl;
    return false;
}

// temporary query function , needs also to be refractored
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


int32_t CuckooFilter::generateFirstIndex(string value, int singleTableLength){

	int32_t index;
    Hashing hashing;
    HashNumber hn;
    cout << "bucket_size u generateFirstIndex = " << bucket_size << endl;

    string hashFromValue = hashing.hash_f(value);

    uint64_t hashAsNumber = hn.hash_to_number(hashFromValue);

    uint64_t tmp = 9;
    uint64_t tmp2 = 4;
    uint64_t tmp3 = tmp % tmp2;

    cout << singleTableLength << endl;

    index = uint64_t(hashAsNumber) % uint64_t(singleTableLength);

    return index;
	
}

int32_t CuckooFilter::generateSecondIndex(string value, string fingerprint, int single_table_length){ // for now, fingerprint is a fixed inserted value

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

    cout << "ušao sam u tryInsert" << endl;
    cout << "bucket size u tryInsert = " << bucket_size << endl;

    for(int i = 0; i < MAX_RELOCATION; i++){
        if(insert(value)) {
            cout << "vratio sam se iz inserta sve 5" << endl;
            return true;
        }

        else {
            cout << "insert nije uspio i idemo dalje" << endl;
            Hashing hashing;
            VictimGenerator vg;
            cout << "bucket_size je ovdje: " << bucket_size << endl;
            int victimIndex = vg.selectVictim(bucket_size);
            cout << "dalje 2" << endl;
            string valueFingerprint = hashing.fingerprint(value);
            cout << "dalje 3" << endl;
            int32_t valueFirstIndex = generateFirstIndex(value,single_table_length);
            //int32_t valueSecondIndex = generateSecondIndex(value,valueFingerprint, single_table_length);
            string victim = bucket[valueFirstIndex].stored_kmer[victimIndex];
            cout << "dalje 4" << endl;
            bucket[valueFirstIndex].stored_kmer[victimIndex] = value;
            cout << "dalje 5" << endl;
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

bool CuckooFilter::generate_children(int single_table_length, int bucket_size, int curr_level) {
    right_child = new CuckooFilter(single_table_length, bucket_size, curr_level + 1);
    right_child->parent = this;
    left_child = new CuckooFilter(single_table_length, bucket_size, curr_level + 1);
    left_child->parent = this;
    return true;
}


string CuckooFilter::CF_string() {
    stringstream ss;
    ss << "CF: empty=" << this->isEmpty << ", full=" << this->isFull << endl;
    ss << "\t left_child = " << get_left_child() << ", right_child = " << get_right_child() << endl;
    return ss.str();
}