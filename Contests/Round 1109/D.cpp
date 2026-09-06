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
        cin >> n>>m;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll>pref(n,0);
        pref[0]=vec[0];
        for(int i=1;i<n;i++)pref[i]=pref[i-1]+vec[i];
        vector<ll>b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
            b[i]--;
        }
        sort(b.begin(),b.end());

        ll ans=accumulate(vec.begin(),vec.end(),0ll);
        vector<ll>minpref=pref;
        vector<ll>maxpref=pref;
        minpref[b[0]]=min(minpref[b[0]],-minpref[b[0]]);
        maxpref[b[0]]=max(maxpref[b[0]],-maxpref[b[0]]);
        ans=max(ans,pref[n-1]-pref[b[0]]+maxpref[b[0]]);

        for(int i=1;i<m;i++){
            ll ans1=-(pref[b[i]]-pref[b[i-1]])-minpref[b[i-1]];
            ll ans2=(pref[b[i]]-pref[b[i-1]])+minpref[b[i-1]];
            ll ans3=(pref[b[i]]-pref[b[i-1]])+maxpref[b[i-1]];
            ll ans4=-(pref[b[i]]-pref[b[i-1]])-maxpref[b[i-1]];
            minpref[b[i]]=min({ans1,ans2,ans3,ans4});
            maxpref[b[i]]=max({ans1,ans2,ans3,ans4});
            ans=max(ans,pref[n-1]-pref[b[i]]+maxpref[b[i]]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
