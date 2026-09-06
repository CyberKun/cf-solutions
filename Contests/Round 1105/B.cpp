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

ll sol(ll exp){
    ll base=2;
    ll res=1;
    base%=MOD;
    while(exp>0){
        if(exp%2==1){
            res=(res*base)%MOD;
        }
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n,m,r,c;
        cin>>n>>m>>r>>c;
        cout<<sol((r*c-1)+((m-c)*(r-1)+(n-r)*(c-1)))<<'\n';
    }
    return 0;
}
