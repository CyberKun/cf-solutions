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

ll power(ll base, ll exp, ll mod){
    ll res = 1;
    base %= mod;
    while (exp > 0){
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n, ll mod){
    return power(n, mod - 2, mod);
}

ll nCr_mod(ll n, ll r, ll mod){
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r > n / 2)
        r = n - r;

    ll num = 1;
    for (ll i = 0; i < r; i++){
        num = (num * ((n - i) % mod)) % mod;
    }

    ll den = 1;
    for (ll i = 1; i <= r; i++){
        den = (den * i) % mod;
    }
    return (num * modInverse(den, mod)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n , k;
        cin >> n >> k;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin(),vec.end() , [](auto &a , auto &b) {return a > b;});
        map<ll,ll> fq;
        for(int i = 0 ; i < n ; i++) fq[vec[i]]++;
        map<ll,ll>fq1;
        for(int i = 0 ; i < k ; i++) fq1[vec[i]]++;
        ll n1 = fq[vec[k-1]] , c1 = fq1[vec[k-1]];
        cout << nCr_mod(n1,c1 , 1e9+7) << '\n';
    }
    return 0;
}
