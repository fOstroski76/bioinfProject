// code written by Elena

#include <stdlib.h>
#include "CF.h"

class Tree {
    public:
        CF* node;
        CF* left_child;
        CF* right_child;
        int curr_level;

        Tree(size_t list_size, size_t bucket_capacity, int curr_level) {
            node = new CF(list_size, bucket_capacity, curr_level);
            left_child = new CF(list_size, bucket_capacity, curr_level+1);
            right_child = new CF(list_size, bucket_capacity, curr_level+1);
            curr_level = curr_level;
        }
};