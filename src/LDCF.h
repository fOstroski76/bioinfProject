// code written by Elena

#include <string>
// #include "CF.h"
#include "Tree.h"

using namespace std;

class LDCF {
    private:

        size_t list_size;
        size_t bucket_size;

        CF* node;
        CF* left_child;
        CF* right_child;

    public:
        Tree* tree;
        int curr_level;

        LDCF(size_t list_size, size_t bucket_size);
        bool insert(const string s);
        bool query(const string s);
        bool del(const string s);

        CF* get_node();
        CF* get_left_child();
        CF* get_right_child();

        LDCF* get_child(LDCF* node, int i, const string prefix);

        const string get_prefix(const string s, int level);
};
