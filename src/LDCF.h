// code written by Elena

#include <string>
#include "cuckoofilter.h"

using namespace std;

class LDCF {
    private:

        int total_capacity;
        int single_table_length;


        int list_size;
        int bucket_size;

        CuckooFilter* node;
        CuckooFilter* left_child;
        CuckooFilter* right_child;

    public:
        int curr_level;

        int counterTotal; // counts total amount of stored elements in all cuckoo filters

        LDCF(int total_capacity, int list_size, int bucket_size);
        bool insert(string s);
        bool query(const string s);
        bool del(const string s);

        CuckooFilter* get_node();
        CuckooFilter* get_left_child();
        CuckooFilter* get_right_child();

        int get_single_table_length();
};