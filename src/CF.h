// code written by Elena

#include <stddef.h>

using namespace std;

class CF {
    private:
        size_t list_size;
        int capacity;
        CF* right_child;
        CF* left_child;
        CF* parent;
        // friend ostream& operator<<(ostream &s, const CF &cf);

    public:
        bool full;
        bool empty;

        CF(size_t list_size, size_t bucket_size);
        string CF_string();
        CF* get_right_child();
        CF* get_left_child();
        CF* get_parent();
        bool generate_children(size_t list_size, size_t bucket_size);
};