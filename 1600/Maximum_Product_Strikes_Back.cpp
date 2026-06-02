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
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        int i = 0 , j = 0;
        ll ans = 0;
        ll st = n , ed = 0;
        while(i < n) {

            while(j < n && vec[j] != 0) j++;
            while(i < n && vec[i] == 0)i++;
            if(i==n) break;

            ll ct = 0;
            for(int k = i ; k < j ; k++) {
                if(vec[k] < 0) ct++;
            }

            if(ct%2==0) {
                ll temp = 0;
                for(int k = i ; k < j ; k++) if(abs(vec[k])==2) temp++;
                if(temp > ans) {
                    st = i , ed = n-j;
                }
                ans = max(ans , temp);
            }
            else {
                int sst = i , eed = j;
                for(int k = i ; k < j ; k++) {
                    sst = k;
                    if(vec[k] < 0) break;
                }
                for(int k = j-1 ; k >= i ; k--) {
                    eed = k;
                    if(vec[k] < 0) break;
                }

                ll tee1 = 0 , tee2 = 0;
                for (int k = sst + 1; k < j; k++) if(abs(vec[k])==2)tee1++;
                for(int k = i ; k < eed ; k++) if(abs(vec[k])==2)tee2++;

                if(tee1 > tee2) {
                    ll temp = 0;
                    for(int k = sst+1 ; k < j ; k++) if(abs(vec[k])==2)temp++;
                    if (temp > ans){
                        st = sst+1, ed = n - j;
                    }
                    ans = max(ans, temp);
                }
                else {
                    ll temp = 0;
                    for (int k = i; k < eed; k++) if (abs(vec[k]) == 2) temp++;
                    if (temp > ans){
                        st = i, ed = n - (eed);
                    }
                    ans = max(ans, temp);
                }
            }
            i = j+1;
            j++;
        }
        cout << st << ' ' << ed << '\n';
    }
    return 0;
}
