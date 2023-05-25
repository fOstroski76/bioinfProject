// code written by Elena

#include <string>
// #include "CF.h"
#include "Tree.h"
#include "cuckoofilter.h"

using namespace std;

class LDCF {
    private:

        int totalCapacity;
        int single_table_length;


        size_t list_size;
        size_t bucket_size;

        CuckooFilter* node;
        CuckooFilter* left_child;
        CuckooFilter* right_child;

    public:
        Tree* tree;
        int curr_level;

        int counterTotal; // counts total amount of stored elements in all cuckoo filters

        LDCF(int totalCapacity, size_t list_size, size_t bucket_size);
        bool insert(const string s);
        bool query(const string s);
        bool del(const string s);

        CuckooFilter* get_node();
        CuckooFilter* get_left_child();
        CuckooFilter* get_right_child();

        LDCF* get_child(LDCF* node, int i, const string prefix);

        const string get_prefix(const string s, int level);
};
