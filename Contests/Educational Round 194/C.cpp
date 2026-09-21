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
        ll x,y;
        cin>>x>>y;
        int ans=0,ops=0;

        for(int i=29;i>=0;i--){
            int bitx=(x>>i)&1;
            int bity=(y>>i)&1;

            if(bitx!=bity){
                ans|=(1<<i);
                continue;
            }

            if(bity==0){
                ll inc=(1ll<<i)-(y&((1ll<<i)-1));
                if(((x>>i)==((x-inc)>>i))){
                    y+=inc;
                    x-=inc;
                    ans|=(1<<i);
                    ops+=inc;
                }
                continue;
            }

            ll dec=(x&((1ll<<i)-1))+1;
            if(((y>>i)==((y+dec)>>i))){
                y+=dec;
                x-=dec;
                ans|=(1<<i);
                ops+=dec;
            }
        }
        cout<<ans<<' '<<ops<<'\n';
    }
    return 0;
}
