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
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        for(int i = 0 ; i < n ; i++) {
            vector<ll>pre(n,0) , pre2(n,0);
            ll num = 0 , num2 = 0;
            for(int j = 1 , k = n-1 ; j < n ; j++,k--) {
                pre[j] = max(num , vec[(i+j-1)%n]);
                pre2[k] = max(num2 , vec[(i+k)%n]);
                num = pre[j];
                num2 = pre2[k];
            }

            ll sumo = 0;
            for(int j = 1 ; j < n ; j++) sumo += min(pre[j],pre2[j]);

            cout << sumo << ' ';
        }
        cout << '\n';
    }
    return 0;
}
