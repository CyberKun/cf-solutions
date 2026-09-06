#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n,q;
        cin >> n>>q;
        string s;
        cin>>s;
        string s1,s2;
        for(int i=0;i<n;i++){
            if(i%2){
                s1+='0';
                s2+='1';
            }
            else{
                s1+='1';
                s2+='0';
            }
        }

        int ct=0;
        vector<ll>seg1(n+1,0),seg2(n+1,0),mis1(n+1,0),mis2(n+1,0);
        for(int i=1;i<=n;i++){
            mis1[i]=(s[i-1]!=s1[i-1]);
            mis2[i]=(s[i-1]!=s2[i-1]);
            seg1[i]=seg1[i-1]+(mis1[i]==1&&mis1[i-1]==0);
            seg2[i]=seg2[i-1]+(mis2[i]==1&&mis2[i-1]==0);
        }
        for(int i=0;i<q;i++){
            ll l,r,k;
            cin>>l>>r>>k;
            ll ans1=seg1[r]-seg1[l]+mis1[l];
            ll ans2=seg2[r]-seg2[l]+mis2[l];
            ll ans = min(ans1, ans2);
            if(ans<=k)cout<<"Yes\n";
            else cout<<"No\n";
        }


    }
    return 0;
}
