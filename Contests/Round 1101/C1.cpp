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
        ll n , x , s;
        cin >> n >> x >> s;
        string ss;
        cin >> ss;

        ll ans = 0;
        for(int i = 0 ; i <= x ; i++) {
            ll es = 0 , is = x-i , ai = i;
            ll ct = 0;
            for(int j = 0 ; j < n ; j++) {
                if(ss[j] == 'I' && is) {
                        is--;
                        ct++;
                        es += s-1;
                } 
                else if(ss[j] == 'E' && es) {
                        es--;
                        ct++;
                }
                else if(ss[j] == 'A') {
                    if(ai) {
                        ai--;
                        es += s-1;
                        ct++;
                    }
                    else if(es) {
                        es--;
                        ct++;
                    }
                }
            }
            ans = max(ans, ct);
        }
        cout << ans << '\n';
    }
    return 0;
}
