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

    ll n , m;
    cin >> n >> m;
    vector<ll> vec1(n) , vec2(m);
    for(int i = 0 ; i < n ; i++) cin >> vec1[i];
    for(int i = 0 ; i < m ; i++) cin >> vec2[i];

    vector<vector<ll>>dp(n , vector<ll>(min(n,m)+1 , 1001));

    for(int i = 0 ; i < m ; i++) {
        if(vec2[i]==vec1[0]) {
            dp[0][1] = i;
            break;
        }
    }

    for(int i = 0 ; i < n ; i++) dp[i][0]=-1;

    for(int i = 1 ; i < n ; i++) {
        for(int j = 1 ; j <= min((ll)i+1 , min(n,m)) ; j++) {
            dp[i][j] = dp[i-1][j];
            for(int k = dp[i-1][j-1]+1 ; k < m ; k++) {
                if(vec2[k]==vec1[i]) {
                    dp[i][j]=min(dp[i][j] ,(ll)k);
                    break;
                }
            }
        }
    }

    int ans=0;
    vector<ll> ass;
    for(int i = min(n,m) ; i >= 1 ; i--) {
        if(dp[n-1][i]!=1001) {
            ans=i;
            int j=n-1 , k=i;
            while(j>=0 && k>0) {
                if(j<0)break;
                else if(j==0) {
                    ass.push_back(vec2[dp[j][k]]);
                    j--;
                    k--;
                }
                else{
                    if(dp[j][k]!=dp[j-1][k]){
                        ass.push_back(vec2[dp[j][k]]);
                        k--;
                    }
                    j--;
                }
            }
            break;
        }
    }
    cout << ans << '\n';
    reverse(ass.begin(),ass.end());
    for(int i = 0 ; i < ass.size() ; i++) cout << ass[i] << ' ';
    cout << '\n';
    return 0;
}
