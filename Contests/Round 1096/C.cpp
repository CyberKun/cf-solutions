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

        map<ll,ll> fq6 , fq2 , fq3;
        ll ct2 = 0 , ct3 = 0;
        for(int i = 0 ; i < n ; i++) {
            if(vec[i] % 6 == 0) fq6[vec[i]]++;
            else if(vec[i] % 3 == 0) fq3[vec[i]]++;
            else if(vec[i] % 2 == 0) fq2[vec[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (fq2[vec[i]])
                cout << vec[i] << ' ';
        }

        for(int i = 0 ; i < n ; i++) {
            if(!fq2[vec[i]] && !fq3[vec[i]] && !fq6[vec[i]]) cout << vec[i] << ' ';
        }

        

        for (int i = 0; i < n; i++)
        {
            if (fq3[vec[i]])
                cout << vec[i] << ' ';
        }

        for (int i = 0; i < n; i++)
        {
            if (fq6[vec[i]])
                cout << vec[i] << ' ';
        }

                cout << '\n';
    }
    return 0;
}
