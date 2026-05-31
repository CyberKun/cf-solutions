#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long

void solve()
{
    int n, x, s;
    if (!(cin >> n >> x >> s))
        return;

    string u;
    cin >> u;

    // dp[j] tracks the maximum people seated having opened exactly j tables.
    // Initialized to -1 to represent unreachable states.
    vector<ll> dp(x + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        // Traverse backwards to update the current DP state in-place
        for (int j = x; j >= 0; j--)
        {
            ll num = dp[j];
            if (num == -1)
                continue;

            // 'I' or 'A' can open a new empty table (moves state to j + 1)
            if (u[i] == 'I' || u[i] == 'A')
            {
                if (j + 1 <= x && num + 1 > dp[j + 1])
                {
                    dp[j + 1] = num + 1;
                }
            }

            // 'E' or 'A' can join a non-empty table if seats are available
            if (u[i] == 'E' || u[i] == 'A')
            {
                if (j * (ll)s - num > 0 && num + 1 > dp[j])
                {
                    dp[j] = num + 1;
                }
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= x; j++)
    {
        if (dp[j] > ans)
        {
            ans = dp[j];
        }
    }

    cout << ans << "\n";
}

int main()
{
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}