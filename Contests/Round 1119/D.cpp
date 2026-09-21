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
        int ct0=0;
        for(int i=0;i<n;i++){
            if(vec[i]==0)ct0++;
        }
        if(ct0==1){
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        bool done=false;
        for(int i=0;i<n;i++){
            if(vec[i]!=0)cout<<'A';
            else if(vec[i]==0&&!done){
                cout<<'B';
                done=true;
            }
            else cout<<'C';
        }
        cout<<'\n';
    }
    return 0;
}
