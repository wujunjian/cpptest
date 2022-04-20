#include <iostream>
#include <unistd.h>
using namespace std;
//host
int main() {

    char hostname[128];
    int ret = gethostname(hostname, sizeof(hostname));
    if (ret == -1) {
        cout << "te_error:gethostname fail" << endl;
        return false;
    }
    cout << "hostname:[" << hostname << "]" << endl;
}