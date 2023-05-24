#include <string>

using namespace std;

class BucketElement {
    private:
        string hash;
        string fingerprint;
    public:
        string get_hash();
        string get_fingerprint();
};