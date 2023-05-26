// code written by Elena

#include <iostream>
#include <string>
#include "LDCF.h"

int main() {
    int total_capacity = 40;
    int CF_size = 4;
    int bucket_size = 4;

    LDCF* ldcf = new LDCF(total_capacity, CF_size, bucket_size);
    // cout << "ldcf.stl " << ldcf->get_single_table_length() << endl;
    CuckooFilter* node = ldcf->get_node();
    // cout << "prvi" << endl;

    // left and right child in LDCF class not needed?!    
    CuckooFilter* left_child = ldcf->get_left_child();
    // cout << "drugi" << endl;
    CuckooFilter* right_child = ldcf->get_right_child();
  // cout << "treći" << endl;

    string seq1 = "ATGATGCGCTGCTAGCTGCATG";
    bool tmp = ldcf->insert(seq1);
    // ldcf->get_node()->printContents();
  // cout << "četvrti" << endl;

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
    s1 = "fffsff";
    ldcf->insert(s1);
    s1 = "ekfsekfnek";
    ldcf->insert(s1);
    s1 = "fff4sdaff";
    ldcf->insert(s1);
    s1 = "ek4fsdaekfnek";
    ldcf->insert(s1);
    s1 = "f4ff2ff";
    ldcf->insert(s1);
    s1 = "ekf2e4kfnek";
    ldcf->insert(s1);
    s1 = "fff24sff";
    ldcf->insert(s1);
    s1 = "2dd4dd";
    ldcf->insert(s1);
    s1 = "fffs2daf4f";
    ldcf->insert(s1);
    s1 = "ekfs2da4ekfnek";
    ldcf->insert(s1);
    s1 = "ekfekf4nek";
    ldcf->insert(s1);
    s1 = "fffsf4f";
    ldcf->insert(s1);
    s1 = "ekfsekf4nek";
    ldcf->insert(s1);
    s1 = "fffsda4ff";
    ldcf->insert(s1);
    s1 = "ekfsda4ekfnek";
    ldcf->insert(s1);
    s1 = "fff2f4f";
    ldcf->insert(s1);
    s1 = "ekf2ekf4nek";
    ldcf->insert(s1);
    s1 = "fff2sf4f";
    ldcf->insert(s1);
    s1 = "2ddd4d";
    ldcf->insert(s1);
    s1 = "fffs2da4ff";
    ldcf->insert(s1);
    s1 = "ekfs2da4ekfnek";
    ldcf->insert(s1);


    s1 = "fffs7ff";
    ldcf->insert(s1);
    s1 = "ekfsek7fnek";
    ldcf->insert(s1);
    s1 = "fff4sda7ff";
    ldcf->insert(s1);
    s1 = "ek4fsd7aekfnek";
    ldcf->insert(s1);
    s1 = "f4ff27ff";
    ldcf->insert(s1);
    s1 = "ekf2e46kfnek";
    ldcf->insert(s1);
    s1 = "fff246sff";
    ldcf->insert(s1);
    s1 = "2dd46dd";
    ldcf->insert(s1);
    s1 = "fff6s2daf4f";
    ldcf->insert(s1);
    s1 = "ek6fs2da4ekfnek";
    ldcf->insert(s1);
    s1 = "e6kfekf4nek";
    ldcf->insert(s1);
    s1 = "6fffsf4f";
    ldcf->insert(s1);
    s1 = "ekfsekf54nek";
    ldcf->insert(s1);
    s1 = "fffsda54ff";
    ldcf->insert(s1);
    s1 = "ekfsd5a4ekfnek";
    ldcf->insert(s1);
    s1 = "fff25f4f";
    ldcf->insert(s1);
    s1 = "ekf52ekf4nek";
    ldcf->insert(s1);
    s1 = "ff5f2sf4f";
    ldcf->insert(s1);
    s1 = "25ddd4d";
    ldcf->insert(s1);
    s1 = "5fffs2da4ff";
    ldcf->insert(s1);
    s1 = "ekfs2da45ekfnek";
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
    
    // ldcf->get_node()->printContents();

    cout << ldcf->get_node()->CF_string() << endl;
    // cout << ldcf->get_left_child()->CF_string() << endl;
    // cout << ldcf->get_right_child()->CF_string() << endl;

    // CuckooFilter* np = nullptr;
    // cout << np << endl;

    cout << "Query test:" << endl;

    if(ldcf->query("elenazelenablablabla")){
        cout << ("Nađen ekfs2da45ekfnek") << endl;
    }

    if(ldcf->del(s1)){
        cout << ("obrisan ekfs2da45ekfnek") << endl;
    }
    else {
        cout << "nije obrisan!" << endl;
    }


    if(ldcf->query("ekfs2da45ekfnek")){
        cout << "Nađen ekfs2da45ekfnek" << endl;
    }
    else {
        cout << "nije nađen" << endl;
    }


    if(ldcf->del(s1)){
        cout << ("obrisan ekfs2da45ekfnek") << endl;
    }
    else {
        cout << "nije obrisan!" << endl;
    }

    return 0;
}

// g++ -I/usr/include/openssl/ testLDCF.cpp Hashing.cpp HashNumber.cpp cuckoofilter.cpp selectVictim.cpp CF.cpp LDCF.cpp Localizing.cpp -lcrypto -o testLDCF