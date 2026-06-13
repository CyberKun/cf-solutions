#include "testlib.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    // Initialize testlib generator
    registerGen(argc, argv, 1);

    // Get the test file index from the command line argument
    int test_index = 1;
    if (argc > 1)
    {
        test_index = atoi(argv[1]);
    }

    int t;
    int sum_n;

    // Test sizing based on index
    if (test_index <= 3)
    {
        // Small tests to catch basic logic errors
        t = rnd.next(5, 10);
        sum_n = rnd.next(50, 200);
    }
    else
    {
        // Large tests to push time complexity (O(N^2) will fail)
        t = rnd.next(10, 50);
        sum_n = 200000;
    }

    // Distribute 'sum_n' across 't' testcases randomly, ensuring every n >= 2
    vector<int> n_list(t, 2);
    int remaining = sum_n - 2 * t;
    for (int j = 0; j < remaining; j++)
    {
        n_list[rnd.next(0, t - 1)]++;
    }

    // Output number of testcases
    println(t);

    for (int i = 0; i < t; i++)
    {
        int n = n_list[i];
        println(n);

        vector<int> a(n);

        // Assign array behavior to ensure maximum test coverage
        int type = rnd.next(0, 5);

        if (test_index >= 4 && test_index <= 6)
            type = 0; // Pure random
        if (test_index >= 7 && test_index <= 9)
            type = 1; // Increasing
        if (test_index >= 10 && test_index <= 12)
            type = 2; // Decreasing
        if (test_index >= 13 && test_index <= 14)
            type = 3; // All identical
        if (test_index >= 15 && test_index <= 17)
            type = 4; // Left small, Right big
        if (test_index >= 18 && test_index <= 19)
            type = 5; // Small range random

        int max_val = 1000000000;

        if (type == 0)
        {
            for (int j = 0; j < n; j++)
                a[j] = rnd.next(1, max_val);
        }
        else if (type == 1)
        {
            for (int j = 0; j < n; j++)
                a[j] = rnd.next(1, max_val);
            sort(a.begin(), a.end());
        }
        else if (type == 2)
        {
            for (int j = 0; j < n; j++)
                a[j] = rnd.next(1, max_val);
            sort(a.rbegin(), a.rend());
        }
        else if (type == 3)
        {
            int val = rnd.next(1, max_val);
            for (int j = 0; j < n; j++)
                a[j] = val;
        }
        else if (type == 4)
        {
            int split = rnd.next(1, n - 1);
            int mid_val = rnd.next(1000, max_val - 1000);
            for (int j = 0; j < split; j++)
                a[j] = rnd.next(1, mid_val - 1);
            for (int j = split; j < n; j++)
                a[j] = rnd.next(mid_val + 1, max_val);
        }
        else
        {
            for (int j = 0; j < n; j++)
                a[j] = rnd.next(1, 10);
        }

        // testlib's println automatically formats space-separated arrays
        println(a);
    }

    return 0;
}