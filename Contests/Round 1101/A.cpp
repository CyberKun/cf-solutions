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
        sort(vec.begin(),vec.end());
        ll ans = n;
        for (int i = 0; i < n;i++) {
            ll ct1 = 0 , ct2 = 0;
            for(int j = 0 ; j < i ; j++) {
                if(vec[j] != vec[i]) ct1++;
                else break;
            }
            for(int j = i+1 ; j < n ; j++) {
                if(vec[j] != vec[i]) ct2++;
            }
            ans = min(ans , max(ct1,ct2));
        }
        cout << ans << '\n';
    }
    return 0;
}
