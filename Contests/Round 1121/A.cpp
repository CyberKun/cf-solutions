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
        vector<ll>idx;
        for(int i=0;i<n;i++){
            if(vec[i]!=(i+1))idx.push_back(i);
        }

        if(idx.empty()){
            cout<<"YES\n";
            continue;
        }

        ll st=0,ed=idx.size()-1;
        while(st<ed){
            swap(vec[idx[st]],vec[idx[ed]]);
            st++;
            ed--;
        }

        vector<ll>srtvec=vec;
        sort(srtvec.begin(),srtvec.end());
        if(vec==srtvec)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
