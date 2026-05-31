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
        ll n , x;
        cin >> n >> x;
        bool psbl = true;
        ll st = n , ed = 5*1e18;
        for(int i = 0 ; i < 62 ; i++) {
            if((!(n&(1ll<<i))) && (!(x&(1ll<<i)))) continue;
            if((!(n&(1ll<<i))) && (x&(1ll<<i))) {
                psbl = false;
                break;
            }
            if ((n & (1ll << i)) && (!(x & (1ll << i)))) {
                ll mask = (1LL << i) - 1;
                ll temp = (n & ~mask) + (1LL << i);
                st = max(st , temp);
            }
            else {
                ll mask = (1LL << i) - 1;
                ll temp = (n & ~mask) + (1LL << i);
                ed = min(ed, temp-1);
            }
        }
        if(!psbl || ed < st) cout << -1 << '\n';
        else cout << st << '\n'; 
    }
    return 0;
}
