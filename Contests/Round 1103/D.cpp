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
        ll n , k;
        cin >> n >> k;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin() , vec.end());
        map<ll,ll> fq;
        for(int i = 0 ; i < n ; i++) {
            fq[vec[i]]++;
        }
        map<ll,bool>dn;
        int ct=0;
        bool psbl = false;
        auto j = fq.rbegin();
        for(auto i = fq.rbegin() ; i != fq.rend() ; i++){
            ll num1 = i->first , num2 = i->second;
            while(j!=i && j->first - i->first > k){
                if(!dn[j->first]) ct--;
                j++;
            }
            if(ct>0 || num2%2==0) {
                psbl = true;
                break;
            }
            else ct++;
        }
        if(psbl) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
