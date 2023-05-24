// code written by Elena

#include <string>
#include <iostream>
#include "HashNumber.h"
#include "Hashing.h"

using namespace std;

void test(const string x) {

    int substr_len = 6;
    int CF_size = 139;
    HashNumber hn;
    Hashing hashing;

    string abc = "abccc";
    string bca = "bcaaa";
    string abb = "abbbb";

    uint64_t n1 = hn.hash_to_number(abc);
    uint64_t n2 = hn.hash_to_number(bca);
    uint64_t n3 = hn.hash_to_number(abb);

    // cout << n1 << endl;
    // cout << n2 << endl;
    // cout << n3 << endl;

    // cout << hn.number_to_hash(n1, 5) << endl;
    // cout << hn.number_to_hash(n2, 5) << endl;
    // cout << hn.number_to_hash(n3, 5) << endl;


    string xi_x = hashing.fingerprint(x);
    cout << "xi_x = " << xi_x << endl; 
    string substr = xi_x.substr(0, substr_len);
    // cout << "substr = " << substr << endl;
    uint64_t xi_x_int = hn.hash_to_number(substr);
    cout << "xi_x_int = " << xi_x_int << endl;
    cout << "number_to_hash = " << hn.number_to_hash(xi_x_int, substr_len) << endl;
    uint64_t xi_x_modulus = xi_x_int % CF_size;
    cout << "xi_x_modulus = " << xi_x_modulus << endl;

    string mu_x = hashing.hash_f(x);
    cout << "mu_x = " << mu_x << endl;
    uint64_t mu_x_int = hn.hash_to_number(mu_x.substr(0, substr_len));
    cout << "mu_x_int = " << mu_x_int << endl;
    cout << "number_to_hash = " << hn.number_to_hash(mu_x_int, substr_len) << endl;
    uint64_t mu_x_modulus = mu_x_int % CF_size;
    cout << "mu_x_modulusssss = " << mu_x_modulus << endl;

    string nu_x = hashing.second_hash_f(mu_x_int, xi_x);

    return;
    

    // cout << uint64_t((xi_x.substr(xi_x.length() - CF_size, CF_size)).c_str()) % CF_size << endl;
    // uint64_t xi_x_modulus = uint64_t((xi_x.substr(xi_x.length() - CF_size, CF_size)).c_str()) % CF_size;
    // cout << "xi_x_modulus = " << xi_x_modulus << endl;

    // uint64_t xi_x_int = uint64_t(xi_x.c_str());
    // cout << "xi_x_int = " << to_string(xi_x_int) << endl; 


    // cout << uint64_t((mu_x.substr(mu_x.length() - CF_size, CF_size)).c_str()) % CF_size << endl;
    // uint64_t mu_x_modulus = uint64_t((mu_x.substr(mu_x.length() - CF_size, CF_size)).c_str()) % CF_size;
    // cout << "mu_x_modulus = " << mu_x_modulus << endl;
    // uint64_t mu_x_int = uint64_t(mu_x.c_str());
    // cout << "mu_x_int = " << to_string(mu_x_int) << endl; 

}

int main() {
    string in = "ATTTGGTAACCACTGTACTGATTACGACG";
    test(in);
    string in2 = "GTACTGGGCGCGCAGAGCGTGNNGTGCGNAGTGCNGTACGNCTAGTGAC";
    test(in2);
    return 0;
}

// g++ -I/usr/include/openssl/ testHashNumber.cpp Hashing.cpp HashNumber.cpp -lcrypto -o testHashNumber