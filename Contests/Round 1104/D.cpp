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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;

        long long total = 1LL * n * (n + 1) / 2;

        // Count substrings with sum mod 3 == 0
        long long cnt[3] = {1, 0, 0};
        int pref = 0;

        for (char c : s)
        {
            if (c == '0')
                pref = (pref + 1) % 3;
            else
                pref = (pref + 2) % 3; // -1 mod 3

            cnt[pref]++;
        }

        long long zero = 0;
        for (int r = 0; r < 3; r++)
        {
            zero += cnt[r] * (cnt[r] - 1) / 2;
        }

        long long good = total - zero;

        // Count odd alternating substrings of length > 1
        long long bad = 0;

        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j + 1 < n && s[j] != s[j + 1])
                j++;

            long long m = j - i + 1;

            long long odd_substrings = (m + 1) * (m + 1) / 4;
            bad += odd_substrings - m; // remove length-1 substrings

            i = j + 1;
        }

        cout << good - bad << '\n';
    }

    return 0;
}
