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
        ll n,k;
        cin >> n>>k;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll>fq(n+1,0);
        ll ct=1;
        for(int i=0;i<n-1;i++){
            if(vec[i]==vec[i+1])ct++;
            else{
                fq[ct]++;
                ct=1;
            }
        }
        fq[ct]++;

        ll ans=0,ct1=0,ct2=0,ct3=0,ct4=0;
        for(int i=n;i>=1;i--){
            if(fq[i]==0)continue;
            ct1+=fq[i];
            ct2+=i*fq[i];
            ct3+=(i*i)*fq[i];
            ct4+=ct1;
            ct4-=(ct3-ct2);
            // cout<<ct1<<'\n';
            // cout<<ct2<<'\n';
            // cout<<ct3<<'\n';
            // cout<<ct4<<'\n';
            if((k-ct2)%ct1==0&&((k-ct2)/ct1>=(1-i)))ans++;
            // cout<<i<<(k-ct2)/ct1<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
