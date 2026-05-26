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
        ll n , m;
        cin >> n >> m;
        vector<pair<ll,ll>> rng(m);
        for (int i = 0; i < m; i++) {
            cin >> rng[i].first >> rng[i].second;
            rng[i].first--;
            rng[i].second--;
        }

        ll q;
        cin >> q;
        vector<ll>vec(q);
        for(int i = 0 ; i < q ; i++) {
            cin >> vec[i];
            vec[i]--;
        }
        ll ans = -1;
        ll lo = 1 , hi = q;
        while(lo <= hi){
            ll mid = (lo+hi)/2;
            map<ll,ll>fq;
            for(int i = 0 ; i < mid ; i++) fq[vec[i]]++;
            vector<ll> pre(n,0);
            pre[0] = fq[0];
            for(int i = 1 ; i < n ; i++) {
                pre[i] = pre[i-1] + fq[i];
            }
            bool psbl = false;
            for(int i = 0 ; i < m ; i++) {
                if(rng[i].first == 0) {
                    if(pre[rng[i].second] > (rng[i].second + 1)/2) {
                        psbl = true;
                        break;
                    }
                }
                else if(pre[rng[i].second] - pre[rng[i].first - 1] > (rng[i].second - rng[i].first + 1)/2) {
                    psbl = true;
                    break;
                }
            }
            if(psbl) {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        cout << ans << '\n';
    }
    return 0;
}
