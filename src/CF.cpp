// code written by Elena

#include <stdlib.h>
#include <stddef.h>
#include <iostream>
#include <sstream>
#include "CF.h"

using namespace std;

// used to generate CuckooFilter.cpp

CF::CF(size_t list_size, size_t bucket_size) {
    list_size = list_size;
    capacity = list_size * bucket_size;
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

string CF::CF_string() {
    stringstream ss;
    ss << "CF: empty=" << this->empty << ", full=" << this->full << endl;
    return ss.str();
}