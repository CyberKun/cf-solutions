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

ll mex(vector<ll> &a, int i, int j)
{
    set<ll> s;

    for (int k = i; k <= j; k++)
    {
        s.insert(a[k]);
    }

    int ans = 0;
    while (s.count(ans))
    {
        ans++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(2*n);
        for (int i = 0; i < 2*n; i++) cin >> vec[i];

        ll ans = 0;
        ll fz = -1 , sz = -1;
        for(int i = 0 ; i < 2*n ; i++) {
            if(vec[i] == 0 && fz == -1) fz=i;
            else if(vec[i] == 0) sz = i; 
        }
        int i = fz+1 , j = sz-1;
        bool psbl = true;
        while(i <= j) {
            if(vec[i] != vec[j]) {
                psbl = false;
                break;
            }
            i++;
            j--;
        }

        if(psbl) {
            i = fz , j = sz;
            while(i >= 0 && j < 2*n && vec[i] == vec[j]) {
                i--;
                j++;
            }
            i++;
            j--;
            ans = mex(vec , i , j);
        }

        i = fz , j = fz;
        while(i >=0 && j < 2*n && vec[i] == vec[j]) {
            i--;
            j++;
        }
        i++;
        j--;
        ans = max(ans , mex(vec,i,j));

        i = sz, j = sz;
        while (i >= 0 && j < 2 * n && vec[i] == vec[j]){
            i--;
            j++;
        }
        i++;
        j--;
        ans = max(ans, mex(vec, i, j));
        cout << ans << '\n';
    }
    return 0;
}
