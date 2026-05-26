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
        vector<ll> vec(n);
        vector<vector<ll>> num(n+1);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            bool chk = true;
            for(int j = 0 ; j < num[i+1].size() ; j++) {
                if(num[i+1][j] == vec[i]) chk = false;
            }
            if(chk) {
                num[i+1].push_back(vec[i]);
                num[vec[i]].push_back(i+1);
            }
        }
        ll fix = 0;
        vector<bool> vis(n+1,false);
        for(ll i = 1 ; i <= n ; i++) {
            if(!vis[i]) {
                vis[i] = true;
                if(num[i].empty()) continue;

                int cur = num[i][0] , par = i;
                vis[cur] = true;
                while(1) {
                    if(num[cur].size() == 2 && par != i && (num[cur][1] == i || num[cur][0] == i)) {
                        fix++;
                        break;
                    }
                    if(!vis[num[cur][0]]) {
                        vis[num[cur][0]] = true;
                        par = cur;
                        cur = num[cur][0];
                    }
                    else if (num[cur].size() == 2 && !vis[num[cur][1]])
                    {
                        vis[num[cur][1]] = true;
                        par = cur;
                        cur = num[cur][1];
                    }
                    else break;
                }
            }
        }
        ll maxy = 0;
        for(int i = 1 ; i <= n ; i++) {
            maxy += (2 - num[i].size());
        }
        maxy /= 2;
        if(maxy) cout << fix+1 << ' ' << fix + maxy << '\n';
        else cout << fix << ' ' << fix << '\n';
        // cout << fix << '\n';

    }
    return 0;
}
