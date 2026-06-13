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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n , m;
        cin >> n >> m;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll> num(m);
        for(int i = 0 ; i < m ; i++) cin >> num[i];

        if(n==1) {
            for(int i = 0 ; i < m ; i++) cout << vec[0] + num[i] << ' ';
            cout << '\n';
            continue;
        }

        ll gc = vec[1] - vec[0];
        for(int i = 2 ; i < n ; i++) {
            gc = __gcd(gc , abs(vec[i]-vec[0]));
        } 
        for(int i = 0 ; i < m ; i++) cout << abs(__gcd(gc , vec[0]+num[i])) << ' ';
        cout << '\n';
    }
    return 0;
}
