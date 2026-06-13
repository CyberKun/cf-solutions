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

ll spf[500005];
void sieve() {
    for(int i = 2 ; i < 500005 ; i++) {
        spf[i]=i;
    }

    for(int i = 2 ; i*i < 500005 ; i++) {
        if(spf[i]==i) {
            for(int j = i*i ; j < 500005 ; j+=i) {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    sieve();

    while (t--) {
        ll n , x;
        cin >> n >> x;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        map<ll,ll> fq;

        for(int i = 0 ; i < n ; i++) {
            while(vec[i] > 1) {
                ll temp = spf[vec[i]] , ct=0;
                while(vec[i]%temp==0) {
                    vec[i]/=temp;
                    ct++;
                }
                fq[temp]+= ct;
            }
        }

        ll ans = 1;
        for(auto i : fq) {
            ans = (ans*(i.second+1))%1000000007;
        }
        cout << ans << '\n';
    }
    return 0;
}
