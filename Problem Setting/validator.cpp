#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Initializes the validator and sets up strict I/O checking
    registerValidation(argc, argv);

    // Read the number of test cases 't'
    // Added '~' to suppress bounds warning
    int t = inf.readInt(1, 10000, "t~");
    inf.readEoln();

    int sum_n = 0;

    for (int test = 1; test <= t; test++)
    {
        // Read 'n' for the current test case
        // Added '~' to suppress bounds warning
        int n = inf.readInt(2, 200000, "n~");
        inf.readEoln();

        // Enforce the sum of n constraint
        sum_n += n;
        ensuref(sum_n <= 200000, "Sum of n over all test cases exceeds 200000 (current sum: %d)", sum_n);

        // Read the array 'a' of size 'n'
        // Added '~' to suppress bounds warning
        inf.readInts(n, 1, 1000000000, "a~");
        inf.readEoln();
    }

    // Ensure there is no trailing garbage data at the end of the file
    inf.readEof();

    return 0;
}