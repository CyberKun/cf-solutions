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

    ll n , k;
    cin >> n >> k;
    vector<ll> vec1(n) , vec2(n);
    for(int i = 0 ; i < n ; i++) cin >> vec1[i];
    for(int i = 0 ; i < n ; i++) cin >> vec2[i];
    ll ans = 0;
    ll lo = 0 , hi = 2*1e9;
    while(lo<=hi) {
        ll mid = lo + (hi-lo)/2;
        bool psbl = true;
        ll temp = k;
        for(int i = 0 ; i < n ; i++) {
            if(vec2[i]/vec1[i] >= mid) continue;
            else {
                ll req = vec1[i]*mid - vec2[i];
                if(temp < req) {
                    psbl = false;
                    break;
                }
                temp -= req;
            }
        }
        if (psbl)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
