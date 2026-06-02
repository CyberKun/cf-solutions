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
        vector<pair<ll,ll>> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i].second >> vec[i].first;
        ll lo = 1 , hi = n , ans = 1;
        while(lo <= hi) {
            ll mid = (lo+hi)/2;
            ll ct1 = 0 , ct2 = mid-1 , cnt = 0;
            for(int i = 0 ; i < n ; i++) {
                if(vec[i].first >= ct1 && vec[i].second >= ct2) {
                    cnt++;
                    ct1++;
                    ct2--;
                }
            }
            if(cnt >= mid) {
                ans = mid;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}
