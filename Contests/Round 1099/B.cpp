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
        vector<ll> pre(n,0);
        pre[0] = vec[0];
        for(int i = 1 ; i < n ; i++) {
            pre[i] = max(vec[i],pre[i-1]);
        }
        ll maxy = 0;
        for(int i = 1 ; i < n ; i++) maxy = max(maxy , pre[i-1]-vec[i]);
        
        bool psbl = true;
        ll minu = 0;
        for(int i = 0 ; i < n ; i++) {
            if (vec[i] >= minu) {
                minu = vec[i]; 
            }
            else if (vec[i] + maxy >= minu){
                minu = vec[i] + maxy; 
            }
            else{
                psbl = false; 
                break;
            }
        }
        if(psbl) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

