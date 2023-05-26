// code written by Elena

#include <iostream>
#include <string>
#include "LDCF.h"

int main() {
    int total_capacity = 40;
    int CF_size = 10;
    int bucket_size = 4;

    LDCF* ldcf = new LDCF(total_capacity, CF_size, bucket_size);
    cout << "ldcf.stl " << ldcf->get_single_table_length() << endl;
    CuckooFilter* node = ldcf->get_node();
    cout << "prvi" << endl;

    // left and right child in LDCF class not needed?!    
    CuckooFilter* left_child = ldcf->get_left_child();
    cout << "drugi" << endl;
    CuckooFilter* right_child = ldcf->get_right_child();
    cout << "treći" << endl;

    string seq1 = "ATGATGCGCTGCTAGCTGCATG";
    bool tmp = ldcf->insert(seq1);
    // ldcf->get_node()->printContents();
    cout << "četvrti" << endl;

    string seq2 = "ATGATGCGCTGNNAGCTGCATG";
    ldcf->insert(seq2);
    // ldcf->get_node()->printContents();

    string seq3 = "ATGANCGCTGCTAATG";
    ldcf->insert(seq3);
    // ldcf->get_node()->printContents();

    string seq4 = "ATGATGTAGCTGNATG";
    ldcf->insert(seq4);
    // ldcf->get_node()->printContents();

    string seq5 = "NNGATGCGCTGCTAGCTGCATG";
    ldcf->insert(seq5);
    // ldcf->get_node()->printContents();

    // just for testing, ignoring the fact k-mers would be the same length
    string seq6 = "ATGC";
    string seq7 = "TGCA";
    string seq8 = "AAAA";
    string seq9 = "ATGG";
    string seq10 = "ACGC";
    string seq11 = "ATTC";
    string seq12 = "TTGC";
    string seq13 = "TTTT";
    string seq14 = "GGGG";
    string seq15 = "CCCC";
    string seq16 = "CGCG";
    string seq17 = "ATAT";
    string seq18 = "AGAG";
    string seq19 = "ACAC";
    string seq20 = "CACA";
    string seq21 = "ATTT";
    string seq22 = "TTTA";
    string seq23 = "CGCC";
    string seq24 = "GGCG";
    string s1 = "h";
    ldcf->insert(s1);
    s1 = "ha";
    ldcf->insert(s1);
    s1 = "hf";
    ldcf->insert(s1);
    s1 = "hv";
    ldcf->insert(s1);
    s1 = "hs";
    ldcf->insert(s1);
    s1 = "haldkj";
    ldcf->insert(s1);
    s1 = "hasjdkasjdh";
    ldcf->insert(s1);
    s1 = "adkasdljaksjd";
    ldcf->insert(s1);
    s1 = "asldkasldasjd";
    ldcf->insert(s1);
    s1 = "asldkajsldkasjdlkadsjlakdj";
    ldcf->insert(s1);
    s1 = "sss";
    ldcf->insert(s1);
    s1 = "elena";
    ldcf->insert(s1);
    s1 = "fran";
    ldcf->insert(s1);
    s1 = "bbb";
    ldcf->insert(s1);
    s1 = "zelena";
    ldcf->insert(s1);
    s1 = "zfran";
    ldcf->insert(s1);
    s1 = "erika";
    ldcf->insert(s1);
    s1 = "fffff";
    ldcf->insert(s1);
    s1 = "ekfekfnek";
    ldcf->insert(s1);

    ldcf->insert(seq6);
    ldcf->insert(seq7);
    ldcf->insert(seq8);
    ldcf->insert(seq9);
    ldcf->insert(seq10);
    ldcf->insert(seq11);
    ldcf->insert(seq12);
    ldcf->insert(seq13);
    ldcf->insert(seq14);
    ldcf->insert(seq15);
    ldcf->insert(seq16);
    ldcf->insert(seq17);
    ldcf->insert(seq18);
    ldcf->insert(seq19);
    ldcf->insert(seq20);
    // cout << "prezivio do tu" << endl; 
    // PROBLEM: when this line above is commented, it results in Segmentation fault (core dumped)


    // this part is fixed
    // cout << "this one is not successful -> why ?!" << endl; // fixed !
    // if this one was unsuccessful, why does the variable not change to full ?!
    // if there is an unsuccessful insert, the isFull should have changed to true and then
    //              the if statement in line 71 in LDCF should have been true 
    //              and 2 new children CF should have been generated
    // fixed ! 



    ldcf->insert(seq21);
    ldcf->insert(seq22);
    ldcf->insert(seq23);
    ldcf->insert(seq24);
    
    ldcf->get_node()->printContents();

    cout << ldcf->get_node()->CF_string() << endl;

    // CuckooFilter* np = nullptr;
    // cout << np << endl;

    return 0;
}

// g++ -I/usr/include/openssl/ testLDCF.cpp Hashing.cpp HashNumber.cpp cuckoofilter.cpp selectVictim.cpp CF.cpp LDCF.cpp Localizing.cpp -lcrypto -o testLDCF