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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll>ans(n+1,-1);
        ll ct = 0;

        for(int i = 0 ; i < n ; i++) {
            ll temp = -1;
            for(int j = 1 ; j <= n ; j++) {
                if(ans[j] == -1) {
                    if(temp == -1) temp = j;
                    else {
                        ll num1 , num2;
                        cout << "? " << temp << ' ' << j << endl;
                        cin >> num1;
                        cout << "? " << j << ' ' << temp << endl;
                        cin >> num2;
                        if(num1 > num2) {
                            ans[temp] = num1;
                        }
                        else ans[j] = num2;
                        temp = -1;
                        ct++;
                    }
                }
                if(ct ==(n-1)) break;
            } 
        }

        cout <<"! ";

        for(int i = 1 ; i <= n ; i++){
            if(ans[i]==-1) cout << n << ' ';
            else cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
