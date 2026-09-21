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
const int MOD=998244353;
const int MAXN=200006;

ll inv[MAXN],p[MAXN],fact[MAXN];

void f1(){
    inv[1]=1;
    p[0]=0;
    p[1]=1;
    fact[0]=1;
    fact[1]=1;

    for(int i=2;i<MAXN;i++){
        fact[i]=(fact[i-1]*i)%MOD;
        inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;
        p[i]=(p[i-1]+inv[i])%MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    f1();

    while (t--) {
        ll n;
        cin>>n;
        vector<ll> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];

        if(n==1){
            cout<<0<<'\n';
            continue;
        }

        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());

        ll ans=0;
        for(int i=0;i<n;i++){
            ll sumo=(p[n-1]-p[i]+MOD)%MOD;
            ll sub=0;
            if(i!=0)sub++;
            ans=(ans+(vec[i]%MOD)*(sumo-sub+MOD)%MOD)%MOD;
        }
        ans=(ans*fact[n-1])%MOD;
        cout<<ans<<'\n';
    }
    return 0;
}
