#include <iostream>
#include <cstring>

using namespace std;

int main() {

    union {
        unsigned long hash_value;
        unsigned char outmd[16];
    } AA;
    cout << sizeof(AA) << " sizeof(unsigned long)=" << sizeof(unsigned long) << endl;
    cout << "sizeof(unsigned long long)=" << sizeof(unsigned long long) << endl;
    memset(AA.outmd, 0x00, sizeof(AA));
    AA.outmd[0] = 'a'; //01100001	97	61	a
    cout << AA.hash_value << endl;




    union test {
        unsigned long hash_value;
        unsigned char outmd[8];
    } BB;
    cout << sizeof(BB) << " sizeof(unsigned long)=" << sizeof(unsigned long) << endl;
    memset(BB.outmd, 0x00, sizeof(BB));



    union test22 {
        unsigned long hash_value;
        unsigned char outmd[8];
    };
    test22 CC;
    cout << sizeof(CC) << " CC sizeof(unsigned long)=" << sizeof(unsigned long) << endl;
    memset(CC.outmd, 0x00, sizeof(BB));


    union test33 {
        unsigned long hash_value;
        unsigned char outmd[8];
    };
    union test22 DD;
    cout << sizeof(DD) << " DD sizeof(unsigned long)=" << sizeof(unsigned long) << endl;
    memset(DD.outmd, 0x00, sizeof(DD));
}