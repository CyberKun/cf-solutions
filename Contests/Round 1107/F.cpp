/****************************************************
██████╗ ██████╗ ██╗   ██╗████████╗███████╗███╗   ██╗
██╔══██╗██╔══██╗██║   ██║╚══██╔══╝██╔════╝████╗  ██║
██████╔╝██████╔╝██║   ██║   ██║   █████╗  ██╔██╗ ██║
██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══╝  ██║╚██╗██║
██████╔╝██║  ██║╚██████╔╝   ██║   ███████╗██║ ╚████║
╚═════╝ ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═══╝
***************************************************/
#include <iostream>
#include <vector>

using namespace std;
#define ll long long

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // cnt[x] stores how many distinct elements have an initial frequency of EXACTLY x
    // Max possible frequency is n, so size n + 1 is sufficient.
    vector<ll> cnt(n + 1, 0);

    int current_freq = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            current_freq++;
        }
        else
        {
            cnt[current_freq]++;
            current_freq = 1;
        }
    }
    cnt[current_freq]++; // Tally the final block of identical elements

    ll ans = 0;
    ll S = 0; // Running total of surviving distinct elements
    ll C = 0; // Running sum of initial frequencies of surviving elements

    // Iterate backwards from the maximum possible frequency down to 1
    for (ll x = n; x >= 1; x--)
    {
        // If no elements have this exact frequency, skip to avoid duplicate state checks
        if (cnt[x] == 0)
            continue;

        // Dynamically add the elements with frequency 'x' into our surviving pool
        S += cnt[x];
        C += x * cnt[x];

        // S = total distinct elements surviving
        // C = their combined starting length
        // We need the gap (k - C) to be evenly distributable among the S elements

        if ((k - C) % S == 0)
        {
            ll F = (k - C) / S;

            // The net shift F must not cause our minimum frequency elements (x) to drop to 0
            if (F >= 1 - x)
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}