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
    vector<ll>primes(1e5+1,0),dupli(1e5+1,0);
    for(int i=2;i<1e5;i++){
        if(primes[i]==0){
            for(int j=i;j<1e5;j+=i){
                primes[j]++;
                ll temp=j;
                while(temp%i==0){
                    dupli[j]++;
                    temp/=i;
                }
            }
        }
    }

    while (t--) {
        ll n;
        cin >> n;
        cout<<dupli[n]+primes[n]-1<<'\n';
    }
    return 0;
}
