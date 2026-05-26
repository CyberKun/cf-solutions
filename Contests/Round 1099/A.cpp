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
        map<ll,ll>fq;
        vector<ll> vec;
        vec.push_back(1);
        int num = 2;
        fq[1]++;
        for(int i = 1 ; i < n ; i++) {
            while(fq[num]) {
                num++;
  
            }
            while(fq[vec[vec.size()-1]+num]) num++;
            vec.push_back(num);
            fq[num]++;
            fq[vec[vec.size()-1]+vec[vec.size()-2]]++;
        }
        for(int i = 0 ; i < n ; i++) cout << vec[i] << ' ';
        cout << '\n';
    }
    return 0;
}
