#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int t = inf.readInt(1, 10000, "t");
    inf.readEoln();
    
    int sum_n = 0;
    
    for (int i = 1; i <= t; i++) {
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int k = inf.readInt(1, n, "k");
        inf.readEoln();
        
        sum_n += n;
        ensuref(sum_n <= 200000, "Sum of n exceeds 200000");
        
        for (int j = 1; j <= n; j++) {
            inf.readInt(0, n, "a_i");
            if (j < n) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    
    inf.readEof();
    return 0;
}