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
        vector<ll> vec(n),vec2(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        for(int i=0;i<n;i++)cin>>vec2[i];
        ll ans1=0;
        bool psbl=true;
        for(int i=0;i<n;i++){
            if(vec2[i]>vec[i]){
                psbl=false;
                break;
            }
            ans1+=(vec[i]-vec2[i]);
        }
        sort(vec.begin(),vec.end());
        sort(vec2.begin(),vec2.end());
        ll ans2=c;
        bool psbl2=true;
        for(int i=0;i<n;i++){
            if(vec2[i]>vec[i]){
                psbl2=false;
                break;
            }
            ans2+=(vec[i]-vec2[i]);
        }
        if(!psbl&&!psbl2)cout<<-1<<'\n';
        else{
            ll ans=INT_MAX;
            if(psbl)ans=min(ans,ans1);
            if(psbl2)ans=min(ans,ans2);
            cout<<ans<<'\n';
        }
        

    }
    return 0;
}
