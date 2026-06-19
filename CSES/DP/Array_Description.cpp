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
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n , m;
    cin >> n >> m;

    vector<ll> vec(n);
    for(int i = 0 ; i < n ; i++) cin >> vec[i];

    vector<vector<ll>> dp(n , vector<ll>(m+2,0));
    if(vec[0]!=0) dp[0][vec[0]]=1;
    else {
        for(int i = 1 ; i <= m ; i++) dp[0][i]=1;
    } 

    for(int i = 1 ; i < n ; i++) {
        if(vec[i]!=0){
            dp[i][vec[i]] = (dp[i-1][vec[i]] + dp[i-1][vec[i]-1] + dp[i-1][vec[i]+1])%MOD;
        }
        else {
            for(int j = 1 ; j <= m ; j++) {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
            }
        }
    }
    ll ans = 0;
    for(int i = 1 ; i <= m ; i++) ans = (ans+dp[n-1][i])%MOD;
    cout << ans << '\n';
    return 0;
}
