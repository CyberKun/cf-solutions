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
        ll n,k;
        cin>>n>>k;

        if(n==1){
            if(k==1){
                cout<<"YES\n";
                cout<<0<<'\n';
            }
            else cout<<"NO\n";
            continue;
        }
        ll temp=(n^k);
        if(temp<n){
            cout<<"YES\n";
            for(int i=1;i<n;i++){
                if(i!=temp)cout<<i<<' ';
            }
            if(temp!=0)cout<<0<<' '<<temp<<'\n';
            else cout<<temp<<'\n';
        }
        else{
            ll ct=0;
            ll tempo=1;
            while(tempo*2<n){
                tempo*=2;
            }
            ll num1=tempo^temp;
            if(num1>=n){
                cout<<"NO\n";
                continue;
            }
            cout << "YES\n";
            for(int i=1;i<n;i++){
                if(i!=num1&&i!=tempo)cout<<i<<' ';
            }
            if(num1!=0)cout<<0<<' '<<num1<<' '<<tempo<<'\n';
            else cout<<0<<' '<<temp<<'\n';
        }
    }
    return 0;
}
