#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Initialize the testlib checker environment
    registerTestlibCmd(argc, argv);

    // Read the number of test cases from the input file
    int t = inf.readInt();

    for (int i = 1; i <= t; i++)
    {
        // Read the jury's expected answer
        long long jury_ans = ans.readLong();

        // Read the participant's output
        long long user_ans = ouf.readLong();

        // Compare the outputs
        if (jury_ans != user_ans)
        {
            quitf(_wa, "Test case %d: Expected %lld coins, but found %lld", i, jury_ans, user_ans);
        }
    }

    // Ensure the participant didn't print any extra garbage at the end
    ouf.readEof();

    // If everything matches perfectly
    quitf(_ok, "All %d test cases correct.", t);
}