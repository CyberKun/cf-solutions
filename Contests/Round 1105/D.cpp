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
        ll n,d;
        cin >> n>>d;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll>pre(n+1,0);
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+vec[i-1];
        ll ans=0;
        for(int i=0;i<n;i++){
            ll temp=(2*d+1)*vec[i]-(pre[((i+d)%n)+1]-pre[(i-d+n)%n]);
            if(((i-d+n)%n)>((i+d)%n))temp-=pre[n];
            if(temp>0)ans+=temp;
        }
        cout<<ans<<'\n';


    }
    return 0;
}
