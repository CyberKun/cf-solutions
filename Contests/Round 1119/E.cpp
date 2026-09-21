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
        for (int i = 0; i < n; i++) cin >> vec[i];
        int ct=0;
        for(int i=0;i<n;i++){
            if(vec[i]==-1)ct++;
        }
        if(ct==n){
            cout<<1;
            for(int i=0;i<n-1;i++)cout<<0;
            cout<<'\n';
            continue;
        }
        vector<ll>ans(n,0);
        bool psbl=true;
        map<ll,set<ll>>st;

        for(int i=0;i<n;i++){
            if(vec[i]>0){
                if(max(0ll,i-vec[i]+1)<=min(n-1,i+vec[i]-1)){
                    st[max(0ll,i-vec[i]+1)].insert(min(n-1,i+vec[i]-1));
                }
            }
        }

        ll j=-1;
        for(int i=0;i<n;i++){
            if(!st[i].empty()){
                j=max(j,*st[i].rbegin());
            }
            if(i>j)ans[i]=1;
        }


        for(int i=0;i<n;i++){
            if(vec[i]!=-1){
                if(i-vec[i]>=0 && i+vec[i]<n){
                    if(ans[i-vec[i]]==0 && ans[i+vec[i]]==0)psbl=false;
                }
                else if(i-vec[i]>=0 && ans[i-vec[i]]==0)psbl=false; 
                else if(vec[i]+i<n && ans[i+vec[i]]==0)psbl=false;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ans[i]==1)cnt++;
        }
        if(psbl==false||cnt==0)cout<<-1<<'\n';
        else{
            for(int i=0;i<n;i++)cout<<ans[i];
            cout<<'\n';
        }
    }
    return 0;
}
