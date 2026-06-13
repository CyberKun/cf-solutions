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

const ll N = 200000;
vector<ll> spf(N + 1);

void buildSPF(){
    for (ll i = 0; i <= N; i++) spf[i] = i;
    for (ll i = 2; i * i <= N; i++){
        if (spf[i] == i){
            for (ll j = i * i; j <= N; j += i) if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<pair<ll, ll>> factorize(ll x){
    vector<pair<ll, ll>> res;
    while (x > 1){
        ll p = spf[x] , cnt = 0;
        while (x % p == 0){
            x /= p;
            cnt++;
        }
        res.push_back({p, cnt});
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    buildSPF();

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        map<ll, multiset<ll>> pows;

        for(int i = 0 ; i < n ; i++) {
            vector<pair<ll,ll>> pw = factorize(vec[i]);
            for(int j = 0 ; j < pw.size() ; j++) pows[pw[j].first].insert(pw[j].second);
        }

        ll ans = 1;
        for(auto it : pows) {
            if(it.second.size() < n-1) continue;
            if(it.second.size()==n-1) it.second.insert(0);
            auto temp = it.second.begin();
            temp++;
            ll powy = *temp;
            while(powy) {
                ans *= it.first;
                powy--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
