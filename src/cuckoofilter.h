// code by Fran

// Base cuckoo filter definitions

#ifndef CUCKOOFILTER_H
#define CUCKOOFILTER_h

#include <string.h>
#include <stdlib.h>
#include <string>

#define MAX_RELOCATION 5

using namespace std;

typedef struct{
	int32_t stored_kmer; // bit_array in their implementation , should be the type of the hash value
} Bucket;

class CuckooFilter {

    private :
        size_t single_table_length;
        Bucket* bucket;
    
    public:


    CuckooFilter(const size_t single_table_length);
    ~CuckooFilter();

    void printContents();

    void insert(int32_t value); // will calculate index within a hashing function, now lets pretend it is precalculated

    void deleteItem(int32_t value); // will check if the element from given index is the same, if not, it will try to delete from alternate address if element matches, otherwise it will fail

    bool query(int32_t value); // checks if the value is present in the filter; currently doesnt yet calculate index from hash 

    int32_t generateFirstIndex(int32_t value, size_t single_table_length); // temporary functions to generate 1st and 2nd index

    int32_t generateSecondIndex(int32_t value, int32_t fingerprint, size_t single_table_length); // fingerprint should be part of the hash,so its data type
};

#endif // CUCKOOFILTER_H