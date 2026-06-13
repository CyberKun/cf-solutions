#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> stack;
    vector<pair<int, int>> pairs;
    vector<bool> matched(n, false);

    // 1. Greedily find all valid matched pairs
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stack.push_back(i);
        }
        else
        {
            if (!stack.empty())
            {
                int j = stack.back();
                stack.pop_back();
                pairs.push_back({j, i});
                matched[j] = true;
                matched[i] = true;
            }
        }
    }

    // 2. Find the index of the LAST unmatched ')'
    int last_unmatched_close = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')' && !matched[i])
        {
            last_unmatched_close = i;
        }
    }

    // 3. Establish the Splitting Point
    int M = last_unmatched_close + 1;
    vector<int> removables;

    // 4. For every pair, pick exactly one safe bracket to remove
    for (auto p : pairs)
    {
        int L = p.first;
        int R = p.second;

        if (L < M)
        {
            removables.push_back(L); // Left side of M: safe to drop '('
        }
        else
        {
            removables.push_back(R); // Right side of M: safe to drop ')'
        }
    }

    // 5. Delete up to 'k' safe brackets to minimize cost
    string ans(n, '0');
    int limit = min((int)removables.size(), k);
    for (int i = 0; i < limit; i++)
    {
        ans[removables[i]] = '1';
    }

    cout << ans << "\n";
}

int main()
{
    // Fast I/O
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