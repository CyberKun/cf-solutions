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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<ll> ans = vec;
        for (int i = 0; i < n - 1; i++){
            ll ct = k - 1;
            ll curr = vec[i];
            ll tag = vec[i] + 1;
            bool fnd = false;
            ans[i] = vec[i];
            for (int j = i + 1; j < n; j++){
                bool bk = false;
                if (vec[j] < curr){
                    ct -= (curr - vec[j]);
                    curr--;
                }
                else if (vec[j] == curr){
                    ans[i] = tag;
                    ct -= (j-i+1);
                    tag++;
                }
                else{
                    ans[i] = tag;
                    fnd = true;
                    ll difu = vec[j] - curr;
                    ll lo = 1, hi = difu;
                    ll as = 0;
                    while (lo <= hi){
                        ll mid = (lo + hi) / 2;
                        if ((j - i) * mid <= ct){
                            as = mid;
                            lo = mid + 1;
                        }
                        else hi = mid - 1;
                    }
                    if (!as) break;
                    ct -= as * (j - i);
                    tag += as;
                    ans[i] = tag;
                    tag++;
                    curr = tag - (j - i+1);
                    if (as != difu) bk = true;
                    ct -= (j-i+1);
                }
                if (ct < 0) break;
                if (bk) break;
            }
        }
        cout << *max_element(ans.begin(), ans.end()) << '\n';
    }
    return 0;
}
