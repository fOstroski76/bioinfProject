// code written by Elena

#include <string>
//#include "CF.h"
//#include "cuckoofilter.h"
#include "LDCF.h"

using namespace std;

class Localize {
    public:
        int get_location(string &str);
        void recover_xi_x(string &str, CuckooFilter* node);
};