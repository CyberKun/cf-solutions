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

    vector<ll> cost(1005 , 1e9);
    cost[1] = 0;
    for (int i = 1; i <= 1000; i++){
        for (int x = 1; x <= i; x++){
            ll num = i + (i / x);
            if (num <= 1000){
                cost[num] = min(cost[num], cost[i] + 1);
            }
        }
    }

    ll t;
    cin >> t;

    while (t--) {
        ll n , k;
        cin >> n >> k;
        vector<ll> vec(n) , pts(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        for (int i = 0; i < n; i++) cin >> pts[i];

        ll maxy = 0;
        for(int i = 0 ; i < n ; i++) maxy = max(maxy , cost[vec[i]]);
        if(k>=maxy*n) {
            cout << accumulate(pts.begin(),pts.end(),0ll) << '\n';
            continue;
        }

        vector<vector<ll>>dp(k+1,vector<ll>(n,0));

        for(int i = 0 ; i <= k ; i++) {
            if(i>=cost[vec[0]]) dp[i][0] = pts[0];
        }

        for(int i = 0 ; i <= k ; i++) {
            for(int j = 1 ; j < n ; j++) {
                dp[i][j] = dp[i][j-1];
                if(i>=cost[vec[j]])dp[i][j] = max(dp[i][j] , dp[i-cost[vec[j]]][j-1] + pts[j]);
            }
        }
        cout << dp[k][n-1] << '\n';
    }
    return 0;
}
