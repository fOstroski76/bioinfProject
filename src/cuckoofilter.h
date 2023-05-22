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

    void deleteItem(size_t index, const std::string value); // will check if the element from given index is the same, if not, it will try to delete from alternate address if element matches, otherwise it will fail

    bool query(size_t index, const std::string value); // checks if the value is present in the filter; currently doesnt yet calculate index from hash 
};

#endif // CUCKOOFILTER_H