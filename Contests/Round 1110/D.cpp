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
        vector<ll>negcnt(n+1,0);
        vector<vector<ll>>arr(m,vector<ll>(3,0));
        for(int i=0;i<m;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
            if(arr[i][0]==2){
                negcnt[arr[i][1]]++;
                if(arr[i][1]!=arr[i][2])negcnt[arr[i][2]]++;
            }
        }

        vector<ll>vc1(n+1,0),vc2(n+1,0);
        for(int i=1;i<=n;i++)vc1[i]=n-negcnt[i];
        vector<ll> vc3 = vc1;
        sort(vc3.begin()+1,vc3.end());
        for (int i = 1; i <= n; i++){
            vc2[i]=lower_bound(vc3.begin()+1,vc3.end(),vc1[i])-vc3.begin()-1;
        }

        vector<ll>ans(n+1);
        for(int i=1;i<=n;i++){
            ans[i]=2*vc2[i]+2*vc1[i]-2*n+1;
        }

        bool psbl=true;
        for(int i=0;i<m;i++){
            ll sumo=ans[arr[i][1]]+ans[arr[i][2]];
            if(arr[i][0]==1&&sumo<0)psbl=false;
            if(arr[i][0]==2&&sumo>=0)psbl=false;
        }
        if(psbl){
            cout<<"YES\n";
            for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
            cout<<'\n';
        }
        else cout<<"NO\n";

    }
    return 0;
}
