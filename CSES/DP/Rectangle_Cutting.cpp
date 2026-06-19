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

    ll a , b;
    cin >> a >> b;

    vector<vector<ll>>dp(a+1,vector<ll>(b+1,1e6));
    for(int i = 1 ; i <= min(a,b) ; i++) dp[i][i]=0;

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout<<dp[a][b]<<'\n';

    return 0;
}
