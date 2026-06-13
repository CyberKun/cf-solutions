#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // pref_max[i] stores the maximum element in the prefix a[0...i]
    vector<int> pref_max(n);
    pref_max[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }

    // suff_min[i] stores the minimum element in the suffix a[i...n-1]
    vector<int> suff_min(n);
    suff_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff_min[i] = min(suff_min[i + 1], a[i]);
    }

    int perfect_splits = 0;

    // We check all possible valid split points (from index 0 to n-2)
    for (int i = 0; i < n - 1; i++)
    {
        // If the maximum on the left is strictly less than the minimum on the right
        if (pref_max[i] < suff_min[i + 1])
        {
            perfect_splits++;
        }
    }

    cout << perfect_splits << "\n";
}

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}