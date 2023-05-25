// code written by Elena

#include <iostream>
#include <string>
#include "CF.h"
#include "Localizing.h"

using namespace std;

int main() {
    size_t list_size = 120;
    size_t bucket_size = 4;
    CF cf = CF(list_size, bucket_size);
    cout << cf.CF_string() << endl;

    if (cf.generate_children(list_size, bucket_size)) {
        cout << "successfully generated children" << endl;
    }
    else {
        cout << "did not manage to generate children" << endl;
    }

    CF* left_child = cf.get_left_child();
    cout << "left_child: " << &left_child << endl;

    cout << "cf: " << &cf << endl;
    cout << "left_child: " << cf.get_left_child() << endl;
    cout << "right_child: " << cf.get_right_child() << endl;
    cout << "cf: " << cf.get_left_child()->get_parent() << endl;

    if (left_child->generate_children(list_size, bucket_size)) {
        cout << "successfully generated left_child\'s children" << endl;
    }
    else {
        cout << "did not manage to generate left_child\'s children" << endl;
    }

    CF* left_c_of_left_c = left_child->get_left_child();
    CF* right_c_of_left_c = left_child->get_right_child();

    cout << "left_child's left child" << left_c_of_left_c << endl;
    cout << "left_child's right child" << right_c_of_left_c << endl;


    Localize loc;
    string fgpt = "abca";
    loc.recover_xi_x(fgpt, left_child);


    return 0;
}

// g++ -I/usr/include/openssl/ testCF.cpp CF.cpp -lcrypto -o testCF