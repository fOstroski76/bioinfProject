#include <iostream>
#include <string>
#include <vector>
#include "generatekmers_h"
#include "LDCF.h"

int main() {
    

    int k = 10;
    
    CuckooFilter filter = CuckooFilter(10,4,0);

    int kmerCounter = 0;

    string seq1 = "ATGATGCGCTGCTAGCTGCATG";
    filter.tryInsert(seq1);
    // ldcf->get_node()->printContents();

    string seq2 = "ATGATGCGCTGNNAGCTGCATG";
    filter.tryInsert(seq2);
    // ldcf->get_node()->printContents();

    string seq3 = "ATGANCGCTGCTAATG";
    filter.tryInsert(seq3);
    // ldcf->get_node()->printContents();

    string seq4 = "ATGATGTAGCTGNATG";
    filter.tryInsert(seq4);
    // ldcf->get_node()->printContents();

    string seq5 = "NNGATGCGCTGCTAGCTGCATG";
    filter.tryInsert(seq5);
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
    filter.tryInsert(s1);
    s1 = "ha";
    filter.tryInsert(s1);
    s1 = "hf";
    filter.tryInsert(s1);
    s1 = "hv";
    filter.tryInsert(s1);
    s1 = "hs";
    filter.tryInsert(s1);
    s1 = "haldkj";
    filter.tryInsert(s1);
    s1 = "hasjdkasjdh";
    filter.tryInsert(s1);
    s1 = "adkasdljaksjd";
    filter.tryInsert(s1);
    s1 = "asldkasldasjd";
    filter.tryInsert(s1);
    s1 = "asldkajsldkasjdlkadsjlakdj";
    filter.tryInsert(s1);
    s1 = "sss";
    filter.tryInsert(s1);
    s1 = "elena";
    filter.tryInsert(s1);
    s1 = "fran";
    filter.tryInsert(s1);

    filter.tryInsert(seq6);
    filter.tryInsert(seq7);
    filter.tryInsert(seq8);
    filter.tryInsert(seq9);
    filter.tryInsert(seq10);
    filter.tryInsert(seq11);
    filter.tryInsert(seq12);
    filter.tryInsert(seq13);
    filter.tryInsert(seq14);
    filter.tryInsert(seq15);
    filter.tryInsert(seq16);
    filter.tryInsert(seq17);
    filter.tryInsert(seq18);
    filter.tryInsert(seq19);
    filter.tryInsert(seq20);
    cout << "prezivio do tu" << endl; 
    filter.tryInsert(seq21);
    filter.tryInsert(seq22);
    filter.tryInsert(seq23);;
    filter.tryInsert(seq24);
    
    
    filter.printContents();

    cout << filter.CF_string() << endl;
    

    float percentage = static_cast<float>(filter.insertedCounter) / static_cast<float>(filter.capacity);
    //filter.printContents();
    cout << "Slots filled:" << filter.insertedCounter << " / " << filter.capacity << "  (" << percentage * 100 << "%)" <<  " Kmer count:" << kmerCounter <<endl;

    cout << "Query results:" << endl;

    int yes = 0;
    int no = 0;
    

    cout << "Yes: " << yes << "  No: " << no << endl;
    return 0;
}
