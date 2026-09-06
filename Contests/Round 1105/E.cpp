#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Create a tripled array to handle circularity easily
    // We only care about the middle n elements
    vector<long long> b(3 * n);
    for (int i = 0; i < 3 * n; ++i)
    {
        b[i] = a[i % n];
    }

    // Prefix sum array
    vector<long long> pref(3 * n + 1, 0);
    for (int i = 0; i < 3 * n; ++i)
    {
        pref[i + 1] = pref[i] + b[i];
    }

    long long max_happiness = 0;

    // Iterate through the middle segment (the original array indices)
    for (int i = n; i < 2 * n; ++i)
    {
        // Range of neighbors: [i-d, i-1] and [i+1, i+d]
        // Sum of neighbors = (Sum of [i-d, i+d]) - a[i]
        long long sum_fov = (pref[i + d + 1] - pref[i - d]) - b[i];

        // Calculate coefficient: 2*d*a[i] - sum_of_neighbors
        long long coeff = 2 * d * b[i] - sum_fov;

        if (coeff > 0)
        {
            max_happiness += coeff;
        }
    }

    cout << max_happiness << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}