// code by Fran

// Base cuckoo filter definitions

#ifndef CUCKOOFILTER_H
#define CUCKOOFILTER_h

#include <string.h>
#include <stdlib.h>
#include <string>

#define MAX_RELOCATION 500

using namespace std;

typedef struct{
	string stored_kmer[4]; // bit_array in their implementation , should be the type of the hash value
} Bucket;

class CuckooFilter {

    private :
        size_t single_table_length;
        Bucket* bucket;
    
    public:
        bool isEmpty;
        bool isFull;
        int capacity;
        int insertedCounter;


    CuckooFilter(const size_t single_table_length);
    ~CuckooFilter();

    void printContents();

    bool insert(string value); // will calculate index within a hashing function, now lets pretend it is precalculated

    bool deleteItem(string value); // will check if the element from given index is the same, if not, it will try to delete from alternate address if element matches, otherwise it will fail

    bool query(string value); // checks if the value is present in the filter; currently doesnt yet calculate index from hash

    bool tryInsert(string value); // will call insert() function and handle victim inserts 

    int32_t generateFirstIndex(string value, size_t single_table_length); // temporary functions to generate 1st and 2nd index

    int32_t generateSecondIndex(string value, string fingerprint, size_t single_table_length); // fingerprint should be part of the hash,so its data type
};

#endif // CUCKOOFILTER_H