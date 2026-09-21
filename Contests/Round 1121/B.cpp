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
        ll n,m;
        cin>>n>>m;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        if(m==1){
            cout<<*max_element(vec.begin(),vec.end())<<'\n';
            continue;
        }
        
        multiset<ll>s;
        ll sumo=0;
        for(int i=0;i<m-1;i++){
            s.insert(vec[i]);
            sumo+=vec[i];
        }
        ll ans=m*vec[m-1]-sumo;

        for(int i=m;i<n;i++){
            ll temp=*s.rbegin();
            if(vec[i-1]<temp){
                s.erase(prev(s.end()));
                s.insert(vec[i-1]);
                sumo-=temp;
                sumo+=vec[i-1];
            }
            ans=max(ans,m*vec[i]-sumo);
        }
        cout<<ans<<'\n';

    }
    return 0;
}
