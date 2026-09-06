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
        ll val=vec[0]-1;
        bool psbl=true;
        for(int i=1;i<n;i++){
            if(vec[i]==(i+1))continue;
            if(vec[i]+val<(i+1)){
                psbl=false;
                break;
            }
            if(vec[i]>i+1){
                val+=(vec[i]-(i+1));
            }
            else{
                val-=((i+1)-vec[i]);
            }
        }
        if(psbl)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
