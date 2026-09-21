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
        vector<vector<ll>>mat(n,vector<ll>(n,0));

        if(k<n||k>=2*n){
            cout<<-1<<'\n';
            continue;
        }

        ll temp=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=temp;
                temp++;
            }
        }

        ll curr=2*n-1;
        
        for(int i=1;i<n;i++){
            if(curr!=k){
                swap(mat[0][i],mat[i][i]);
                curr--;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<' ';
            }
            cout<<'\n';
        }

    }
    return 0;
}
