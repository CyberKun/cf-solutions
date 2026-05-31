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
        vector<pair<double,double>> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i].first;
        for (int i = 0; i < n; i++) cin >> vec[i].second;
        sort(vec.begin(),vec.end());

        vector<pair<double,double>>num(n);
        double maxy1 =-1e18, maxy2 = -1e18;
        for(int i = 0 ; i < n ; i++) {
            num[i].first = vec[i].second - vec[i].first;
            num[i].second = vec[i].second + vec[i].first;
            maxy1 = max(maxy1,num[i].first);
            maxy2 = max(maxy2 , num[i].second);
        }
        double ans = abs(maxy2-maxy1)/2.0;
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}
