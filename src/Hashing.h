// code written by Elena

// because of SHA256Init function, has to be run with: g++ -I/usr/include/openssl/ nameOfFile.cpp -lcrypto
// or need to add "-I/usr/include/openssl/" and "-lcrypto" as arguments in tasks.json if using vscode

#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>     // rand, rand
#include <time.h>       // time
#include "CF.h"
#include "LDCF.h"

using namespace std;

class Hashing {
    public:

        const string fingerprint(const string str);

        const string hash_f(const string str);

};
