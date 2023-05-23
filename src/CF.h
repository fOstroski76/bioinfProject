// code written by Elena

#include <stddef.h>

using namespace std;

class CF {
    private:
        size_t list_size;
        int capacity;

    public:
        bool full;
        bool empty;

        CF(size_t list_size, int capacity, int curr_level);

};