// code by Fran

// Base cuckoo filter definitions

#ifndef CUCKOOFILTER_H
#define CUCKOOFILTER_h

#include <string.h>
#include <stdlib.h>
#include <string>

#define MaxNumberOfKicks 5

using namespace std;

typedef struct{
	std::string stored_kmer; // bit_array in their implementation , should be the type of the hash value
} Bucket;

class CuckooFilter {

    private :
        size_t single_table_length;
        Bucket* bucket;
    
    public:


    CuckooFilter(const size_t single_table_length);
    ~CuckooFilter();

    void printContents();

    void insert(size_t index, string value); // will calculate index within a hashing function, now lets pretend it is precalculated
};

#endif // CUCKOOFILTER_H