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
        for(int i=0;i<n;i++){
            if(vec[i]==1)break;
            if(vec[i]==-1){
                vec[i]=1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(vec[i]==1)break;
            if(vec[i]==-1){
                vec[i]=1;
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(vec[i]==-1)cout<<0<<' ';
            else cout<<vec[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
