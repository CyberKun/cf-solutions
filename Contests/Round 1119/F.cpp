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

        string s;
        cin>>s;
        vector<ll>pre(n,0),suf(n,0);
        pre[0]=(vec[0]==1);
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+(vec[i]==1);
        suf[n-1]=(vec[n-1]==0);
        for(int i=n-2;i>=0;i--)suf[i]=suf[i+1]+(vec[i]==0);

        ll ans=0;
        for(int i=0;i<n;i++){
            if(vec[i]==1)ans+=(suf[i]);
        }
        cout<<ans<<' ';

        int st=0,ed=n-1;
        int ct1=0,ct0=0;

        while(st<n&&vec[st]==0)st++;
        while(ed>=0 && vec[ed]==1)ed--;
        for(int i=0;i<s.length();i++){
            //cout<<s[i]<<' '<<pre[i]<<' '<<suf[i]<<' '<<ct0<<' '<<ct1<<'\n';
            if(st>=ed){
                cout<<0<<' ';
            }
            else if(s[i]=='1'){
                ans-=(suf[st]-ct0);
                cout<<ans<<' ';
                ct1++;
                st++;
                while(st<n&&vec[st]==0)st++;
            }
            else{
                ans-=(pre[ed]-ct1);
                cout<<ans<<' ';
                ct0++;
                ed--;
                while(ed>=0 && vec[ed]==1)ed--;
            }
        }
        cout<<'\n';
    }
    return 0;
}
