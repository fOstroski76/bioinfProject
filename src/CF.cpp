// code written by Elena

#include <stdlib.h>
#include <stddef.h>
#include <iostream>
#include <sstream>
#include "CF.h"

using namespace std;

CF::CF(size_t list_size, size_t bucket_size) {
    list_size = list_size;
    capacity = list_size * bucket_size;
    // curr_level = curr_level;
    full = false;
    empty = true;
    right_child = nullptr;
    left_child = nullptr;
    parent = nullptr;
}

CF* CF::get_right_child() {
    return right_child;
}

CF* CF::get_left_child() {
    return left_child;
}

CF* CF::get_parent() {
    return parent;
}

bool CF::generate_children(size_t list_size, size_t bucket_size) {
    right_child = new CF(list_size, bucket_size);
    right_child->parent = this;
    left_child = new CF(list_size, bucket_size);
    left_child->parent = this;
    return true;
}

// ostream& operator<<(ostream &s, const CF &cf) {
//     return s << "CF: empty=" << cf.empty << ", full=" << cf.full << endl;
// }

string CF::CF_string() {
    stringstream ss;
    ss << "CF: empty=" << this->empty << ", full=" << this->full << endl;
    return ss.str();
}