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
const int MOD=1e9+7;
vector<ll>pows(2*1e5+1);

void pow(){
    ll base=1;
    pows[0]=1;
    for(int i=1;i<=2*1e5;i++){
        base=(base*2)%MOD;
        pows[i]=base;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    pow();

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for(int i = 0; i < n; i++) cin >> vec[i];
        ll ans1=1;
        ll ans2=1;
        ll ct=1;
        ll ct1=0;
        for(int i=0;i<n-1;i++){
            if(vec[i]==vec[i+1])ct++;
            else{
                ans1=(ans1*pows[ct-1])%MOD;
                ct=1;
                if(vec[i]+1==vec[i+1])ct1++;
            }
        }
        ans1=(ans1*pows[ct-1])%MOD;

        if(vec[0]==-1)ans2=(ans1*ct1)%MOD;
        else ans2=0;
        cout<<(ans1+ans2)%MOD<<'\n';

    }
    return 0;
}
