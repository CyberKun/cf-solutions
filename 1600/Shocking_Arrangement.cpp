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
        multiset<ll> pos , neg;
        ll maxy = LLONG_MIN , minu = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            maxy = max(maxy , x);
            minu = min(minu , x);
            if(x >= 0) pos.insert(x);
            else neg.insert(x);
        }
        ll targ = maxy - minu;

        bool psbl = true;
        vector<ll>vec;
        int i = 0 , j = 0;
        ll sumo = 0;
        while(pos.size() || neg.size()) {
            auto it = pos.lower_bound(targ - sumo);
            if(it != pos.begin()) {
                it--;
                vec.push_back(*it);
                sumo += *it;
                pos.erase(it);
            }
            else {
                if(neg.empty()) {
                    psbl = false;
                    break;
                }
                auto ut = neg.lower_bound(-sumo);
                if(ut != neg.end()) {
                    vec.push_back(*ut);
                    sumo += *ut;
                    neg.erase(ut);
                }
                else {
                    ut = prev(neg.end());
                    vec.push_back(*ut);
                    neg.erase(ut);
                    sumo = 0;
                }
            }
        }
        if(!psbl) cout << "No\n";
        else {
            cout << "Yes\n";
            for(int i = 0 ; i < n ; i++) cout << vec[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
