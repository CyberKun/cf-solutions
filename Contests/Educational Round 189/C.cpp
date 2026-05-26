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
        vector<char> vec(n),num(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        for (int i = 0; i < n; i++) cin >> num[i];
        
        ll ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(vec[i] == num[i]){
                continue;
            }
            else if(i == n-1) ans++;
            else if(vec[i] == vec[i+1]) {
                if(num[i] != num[i+1]) {
                    ans++;
                }
                i++;

            }
            else if(num[i] == num[i+1]) {
                if (vec[i] != vec[i+1]){
                    ans++;
                }
                i++;
            }
            else ans++;
        }
       
        cout << ans << '\n';

    }
    return 0;
}
