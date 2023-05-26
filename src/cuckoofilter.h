// code by Fran

// Base cuckoo filter definitions

#ifndef CUCKOOFILTER_H
#define CUCKOOFILTER_h

// #include <string.h>
#include <stdlib.h>
#include <string>

#define MAX_RELOCATION 500

using namespace std;

typedef struct{
	string stored_kmer[16]; // bit_array in their implementation , should be the type of the hash value
} Bucket;

class CuckooFilter {

    private :
        Bucket* bucket;
        int single_table_length;
        uint32_t mask;
    
    public:
        bool isEmpty;
        int bucket_size; // MUST BE LOWER THAN 16 TO WORK!
        bool isFull;
        int capacity;
        int insertedCounter;
        int level; 

        CuckooFilter* left_child;
	    CuckooFilter* right_child;
	    CuckooFilter* parent; 


    CuckooFilter(int single_table_length, int bucket_size, int curr_level);
    ~CuckooFilter();

    string printContents();

    bool insert(string value); // will calculate index within a hashing function, now lets pretend it is precalculated

    bool deleteItem(string value); // will check if the element from given index is the same, if not, it will try to delete from alternate address if element matches, otherwise it will fail

    bool query(string value); // checks if the value is present in the filter; currently doesnt yet calculate index from hash

    bool tryInsert(string value); // will call insert() function and handle victim inserts 

    int32_t generateFirstIndex(string value, int single_table_length); // temporary functions to generate 1st and 2nd index

    int32_t generateSecondIndex(string value, string fingerprint, int single_table_length); // fingerprint should be part of the hash,so its data type

    // code written by Elena
    CuckooFilter* get_left_child();

    CuckooFilter* get_right_child();

    CuckooFilter* get_parent();

    int get_single_table_length();

    int get_bucket_size();

    int get_level();

    bool generate_children(int single_table_length, int bucket_size, int curlevel);

    string CF_string();
};

#endif // CUCKOOFILTER_H