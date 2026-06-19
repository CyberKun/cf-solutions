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
        vector<ll> vec(n) , num(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        for (int i = 0; i < n; i++) cin >> num[i];

        bool psbl=true;
        ll ct=0;
        for(int i = 0 ; i < n ; i++) {
            if(vec[i]<=num[i]) continue;

            ll temp=0;
            for(int j = i+1 ; j<n ; j++) {
                if(vec[j]<=num[i]) {
                    temp=j;
                    break;
                }
            }
            
            if(temp==0) {
                psbl=false;
                break;
            }

            for(int j = temp ; j > i ; j--) {
                swap(vec[j-1],vec[j]);
                ct++;
            }
        }
        if(psbl) cout << ct << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
