#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n,x,y;
        cin >> n>>x>>y;
        map<ll,ll>fq;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++){
            cin >> vec[i];
            fq[vec[i]]=i;
        }
        sort(vec.begin(),vec.end());
        bool psbl=true;
        ll g=__gcd(x,y);
        for(int i=0;i<n;i++){
            ll diff=abs(fq[vec[i]]-i);
            if((diff%g)!=0)psbl=false;
        }
        if(psbl)cout<<"Yes\n";
        else cout<< "No\n";


    }
    return 0;
}
