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
        ll n;
        cin >> n;
        vector<vector<ll>>adj(n+1);
        for(int i=2;i<=n;i++){
            ll u;
            cin>>u;
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
        ll ans=n;
        auto dfs=[&](auto self,ll u , ll par)-> ll{
            ll ct1=-1,ct2=-1;
            for(auto v:adj[u]){
                if(v==par)continue;
                ll temp=self(self,v,u);
                if(temp>ct1){
                    ct2=ct1;
                    ct1=temp;
                }
                else if(temp>ct2)ct2=temp;
            }
            if(ct2!=-1)ans+=(ct2+1);
            return ct1+1;
        };
        dfs(dfs,1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
