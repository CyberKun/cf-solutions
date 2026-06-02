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

    ll t=1;
    // cin >> t;

    while (t--) {
        ll n , m;
        cin >> n >> m;
        string s;
        cin >> s;
        string s1 , s2 , s3 , s4 , s5 , s6;
        string t1 = "abc" , t2 = "acb" , t3 = "bac" , t4 = "bca" , t5 = "cab" , t6 = "cba";
        for(int i = 0; i < n; i++) s1.push_back(t1[i%3]);
        for(int i = 0; i < n; i++) s2.push_back(t2[i%3]);
        for(int i = 0; i < n; i++) s3.push_back(t3[i%3]);
        for(int i = 0; i < n; i++) s4.push_back(t4[i%3]);
        for(int i = 0; i < n; i++) s5.push_back(t5[i%3]);
        for(int i = 0; i < n; i++) s6.push_back(t6[i%3]);
        vector<ll>dp1(n+1,0) , dp2(n+1,0) , dp3(n+1,0) , dp4(n+1,0) , dp5(n+1,0) , dp6(n+1,0);
        for(int i = 0 ; i < n ; i++) {
            dp1[i+1] = dp1[i] + (s[i]!=s1[i]);
            dp2[i+1] = dp2[i] + (s[i]!=s2[i]);
            dp3[i+1] = dp3[i] + (s[i]!=s3[i]);
            dp4[i+1] = dp4[i] + (s[i]!=s4[i]);
            dp5[i+1] = dp5[i] + (s[i]!=s5[i]);
            dp6[i+1] = dp6[i] + (s[i]!=s6[i]);
        } 

        for(int i = 0 ; i < m ; i++) {
            ll l , r;
            cin >> l >> r;
            cout << min({dp1[r]-dp1[l-1],dp2[r]-dp2[l-1],dp3[r]-dp3[l-1],dp4[r]-dp4[l-1],dp5[r]-dp5[l-1],dp6[r]-dp6[l-1]}) << '\n';
        }
    }
    return 0;
}
