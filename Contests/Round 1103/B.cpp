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
        ll n , k;
        cin >> n >> k;
        string vec;
        cin >> vec;
        bool psbl = true;
        for(int i = n-1-k ; i >= 0 ; i--) {
            if(vec[i+k]=='1') {
                vec[i+k]='0';
                if(vec[i]=='1') vec[i]='0';
                else vec[i]='1';
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(vec[i]=='1') {
                psbl = false;
                break;
            }
        }
        if(psbl) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
