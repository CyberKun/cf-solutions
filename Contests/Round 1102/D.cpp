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
        vector<int>v1(n) , v2(n) , v3(n);
        string s1 , s2;
        cin >> s1 >> s2;
        for(int i = 0 ; i < n ; i++) {
            if(s1[i]=='0') v1[i]=0;
            else v1[i]=1;
            if(s2[i]=='0') v2[i]=0;
            else v2[i]=1;
            v3[i]=v1[i]^v2[i];
        }

        ll a0 = 0 , a1 = 0 , b0=0,b1=0,c0=0,c1=0;
        for(int i = 0 ; i < n ; i++) {
            if(v1[i]==0) a0++;
            else a1++;
            if(v2[i]==0) b0++;
            else b1++;
            if(v3[i]==0) c0++;
            else c1++;
        }

        ll num1 = a0*a1 , num2 = b0*b1 , num3 = c0*c1;

        if(k%2) {
            ll ct = ((1<<k)+1)/3;
            cout << (num1+num2+num3)*ct << '\n';
        }
        else {
            ll ct1 = ((1<<k)+2)/3 , ct2= ((1<<k)-1)/3;
            cout << (num1+num2)*ct1 + num3*ct2 << '\n';
        }
    }
    return 0;
}
