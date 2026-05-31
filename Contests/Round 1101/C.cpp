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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n , x , s;
        cin >> n >> x >> s;
        string ss;
        cin >> ss;
        vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));
        dp[0][0] = 0;

        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 0 ; j <= x ; j++) {
                dp[i][j] = dp[i-1][j];
                if(ss[i-1] == 'E') {
                    if ((dp[i - 1][j] != -1 && (j * s) - dp[i - 1][j])) dp[i][j] = max(dp[i][j] , dp[i-1][j]+1);
                }
                else if(ss[i-1] == 'I') {
                    if (j > 0 && dp[i-1][j-1] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
                else {
                    if (j > 0 && dp[i - 1][j - 1] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    if ((dp[i - 1][j] != -1 && (j * s) - dp[i - 1][j])) dp[i][j] = max(dp[i][j], dp[i - 1][j]+1);
                }
            }
        }

        ll ans = 0;
        for(int i = 0 ; i <= x ; i++) {
            ans = max(ans , dp[n][i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
