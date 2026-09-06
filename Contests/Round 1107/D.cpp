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
        vector<ll> vec(n),num(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        for(int i=0;i<n;i++)cin>>num[i];
        vector<ll>tem(n,0);
        if(vec[0]>num[0]){
            cout<<"NO\n";
            continue;
        }
        bool psbl=true;
        ll avl=num[0]-vec[0];
        for(int i=1;i<n;i++){
            if(vec[i]>num[i]){
                ll temp=vec[i]-num[i];
                if(temp<=avl){
                    avl-=temp;
                }
                else{
                    psbl=false;
                    break;
                }
            }
            else avl+=num[i]-vec[i];
        }
        if(psbl)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
