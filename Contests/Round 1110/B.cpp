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
        ll n,c;
        cin >> n>>c;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll>num(n,0);
        for(int i=0;i<n;i++){
            num[i]=vec[i]-c;
        }
        sort(num.begin(),num.end());
        ll ans=0;
        for(int i=0;i<n/2;i++){
            if(num[i]>0)ans+=num[i];
        }
        for(int i=n/2;i<n;i++)ans+=num[i];
        cout<<ans<<'\n';
    }
    return 0;
}
