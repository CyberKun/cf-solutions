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
        ll ans = 0;
        ll minu = vec[n-1];
        vector<ll> inc(n,0);
        for(int i = n-1 ; i >= 0 ; i--) {
            if(minu < vec[i]) {
                inc[i] = vec[i]-minu;
                ans += inc[i];
            }
            minu = min(vec[i],minu);
        }

        vector<ll> lefty(n, -1);
        stack<ll> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vec[st.top()] >= vec[i]){
                st.pop();
            }
            if (!st.empty()){
                lefty[i] = st.top();
            }
            st.push(i);
        }

        ll bonu = 0;
        for(int i = 0 ; i < n ; i++) {
            if(inc[i] == 0) {
                bonu = max(bonu , (ll)(i - lefty[i] - 1));
            }
        }
        cout << ans + bonu << '\n';
    }
    return 0;
}
