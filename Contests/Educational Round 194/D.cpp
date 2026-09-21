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
        string s;
        cin>>s;

        if(s[0]=='0'){
            cout<<-1<<'\n';
            continue;
        }

        bool psbl=false;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1] && s[i]=='0'){
                cout<<-1<<'\n';
                psbl=true;
                break;
            }
        }
        if(psbl)continue;

        if(s.length()==1){
            cout<<1<<'\n';
            continue;
        }

        psbl=true;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1] && s[i]!='0' && s[i+1]!='0'){
                psbl=false;
                break;
            }
        }

        for(int i=0;i<n;i++){
            if (s[i]=='0' && i%2==0){
                psbl=false;
                break;
            }
        }

        if(psbl){
            cout<<1<<'\n';
            continue;
        }

        if(s.find("-++-")!=string::npos||s.find("+--+")!=string::npos){
            cout << 3 << '\n';
        }
        else cout<<2<<'\n';

        // vector<ll>vec;
        // map<ll,ll>mp;
        // ll ct=1;
        // for(int i=0;i<n-1;i++){
        //     if(s[i]==s[i+1])ct++;
        //     else{
        //         vec.push_back(ct);
        //         ct=1;
        //         mp[vec.size()-1]=s[i]-'0';
        //     }
        // }
        // vec.push_back(ct);
        // mp[vec.size()-1] = s[n-1]-'0';

        // bool psbl1=false;
        // for(int i=0;i<vec.size()-1;i++){
        //     if(i==0 && vec[i]%2==0 && mp[i+1]!=0){
        //         cout<<3<<'\n';
        //         psbl1=true;
        //         break;
        //     }
        //     else if(vec[i]%2==0 && mp[i+1]!=0 && mp[i-1]!=0){
        //         cout<<3<<'\n';
        //         psbl1=true;
        //         break;
        //     }
        // }
        // if(psbl1)continue;
        // cout<<2<<'\n';
    }
    return 0;
}
