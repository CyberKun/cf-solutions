/****************************************************
██████╗ ██████╗ ██╗   ██╗████████╗███████╗███╗   ██╗
██╔══██╗██╔══██╗██║   ██║╚══██╔══╝██╔════╝████╗  ██║
██████╔╝██████╔╝██║   ██║   ██║   █████╗  ██╔██╗ ██║
██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══╝  ██║╚██╗██║
██████╔╝██║  ██║╚██████╔╝   ██║   ███████╗██║ ╚████║
╚═════╝ ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═══╝
***************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        // Sorting is helpful here to easily grab the absolute minimum
        sort(vec.begin(), vec.end());

        map<ll, ll> fq;
        for (int i = 0; i < n; i++)
            fq[vec[i]]++;

        ll ct = 0, ct2 = LLONG_MAX; // ct2 initialized to max so min() works later

        // ==========================================
        // PATH 1: Standard greedy reduction
        // ==========================================
        while (fq.size() > 1)
        {
            ll maxy = fq.rbegin()->first, cnt = fq.rbegin()->second;
            fq.erase(maxy);

            ll smax = fq.rbegin()->first;

            while (maxy > smax)
            {
                if (maxy % 2)
                {
                    maxy++;
                    ct += cnt;
                }
                else
                {
                    maxy /= 2;
                    ct += cnt;
                }
            }
            fq[maxy] += cnt;
        }

        // ==========================================
        // PATH 2: If minimum is odd, try adding 1 to it first
        // ==========================================
        if (vec[0] % 2 != 0)
        {
            map<ll, ll> fq1;
            ct2 = 0; // Use the outer ct2, don't redeclare it!

            for (int i = 0; i < n; i++)
            {
                if (vec[i] == vec[0])
                {
                    fq1[vec[i] + 1]++;
                    ct2++; // Charge 1 operation for each minimum element we push up
                }
                else
                {
                    fq1[vec[i]]++; // FIX: Must include the rest of the array!
                }
            }

            // Run the exact same simulation on the modified map
            while (fq1.size() > 1)
            {
                ll maxy = fq1.rbegin()->first, cnt = fq1.rbegin()->second;
                fq1.erase(maxy);

                ll smax = fq1.rbegin()->first;

                while (maxy > smax)
                {
                    if (maxy % 2)
                    {
                        maxy++;
                        ct2 += cnt; // FIX: Accumulate into ct2, not ct!
                    }
                    else
                    {
                        maxy /= 2;
                        ct2 += cnt; // FIX: Accumulate into ct2, not ct!
                    }
                }
                fq1[maxy] += cnt;
            }
        }

        // Output the best of both simulated timelines
        cout << min(ct, ct2) << '\n';
    }
    return 0;
}