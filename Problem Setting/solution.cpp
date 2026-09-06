#include <iostream>
#include <vector>

using namespace std;

// Function to check if we can form at least 'k' segments,
// each having a MEX of at least 'target_mex'
bool check(int target_mex, const vector<int> &a, int k, int n)
{
    if (target_mex == 0)
    {
        // We can always form k segments with MEX >= 0 since n >= k
        return true;
    }

    int segments_formed = 0;
    int required_found = 0;

    // We only care about numbers from 0 to target_mex - 1
    vector<bool> seen(target_mex, false);

    for (int i = 0; i < n; i++)
    {
        if (a[i] < target_mex && !seen[a[i]])
        {
            seen[a[i]] = true;
            required_found++;
        }

        // If we found all required numbers for the current segment
        if (required_found == target_mex)
        {
            segments_formed++;
            required_found = 0;
            // Fast way to reset the 'seen' array without allocating a new one
            fill(seen.begin(), seen.end(), false);
        }
    }

    return segments_formed >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Binary search for the answer
    int left = 0, right = n;
    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (check(mid, a, k, n))
        {
            ans = mid; // mid is possible, try for a larger MEX
            left = mid + 1;
        }
        else
        {
            right = mid - 1; // mid is impossible, try a smaller MEX
        }
    }

    cout << ans << "\n";
}

int main()
{
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