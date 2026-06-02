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
        vector<vector<ll>> adj(n+1);
        map<pair<ll,ll>,ll> rank;

        for(int i = 1 ; i < n ; i++) {
            ll u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            rank[{u,v}] = i;
            rank[{v,u}] = i;
        }
        vector<ll> its(n+1,1);

        queue<int> q;
        vector<bool> vis(n+1 , false);
        vector<ll> par(n+1 , -1);
        q.push(1);
        vis[1] = true;
        for(auto v : adj[1]) {
            vis[v] = true;
            its[v] = 1;
            par[v] = 1;
            q.push(v);
        }

        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : adj[u]){
                if (!vis[v]){
                    its[v] = its[u] + (rank[{v,u}]< rank[{u,par[u]}]);
                    par[v] = u;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << *max_element(its.begin(),its.end()) << '\n';
    }
    return 0;
}
