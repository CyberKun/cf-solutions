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
        vector<vector<int>>adj(n);
        vector<int> degree(n, 0);
        bool possible = true;
        for (int i = 0; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;

            if (max(degree[u],degree[v]) > 2) possible = false;
        }

        if (!possible){
            cout << "No\n";
            continue;
        }

        auto hasOddCycle = [&](int n, vector<vector<int>> &adj) -> bool{
            vector<int> color(n, -1);
            for (int src = 0; src < n; src++){
                if (color[src] != -1)
                    continue;

                queue<int> q;
                q.push(src);
                color[src] = 0;

                while (!q.empty()){
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]){
                        if (color[v] == -1){
                            color[v] = color[u] ^ 1;
                            q.push(v);
                        }
                        else if (color[v] == color[u]){
                            return true;
                        }
                    }
                }
            }

            return false;
        };

        if(hasOddCycle(n , adj)) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
