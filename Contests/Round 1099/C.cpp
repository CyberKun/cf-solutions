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
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end());

        map<ll, ll> fq;
        for (int i = 0; i < n; i++)
            fq[vec[i]]++;

        ll ct = 0;
        map<ll, ll> fq3 = fq; 

        while (fq.size() > 1){
            ll maxy = fq.rbegin()->first, cnt = fq.rbegin()->second;
            fq.erase(maxy);

            ll smax = fq.rbegin()->first;

            while (maxy > smax){
                if (maxy % 2 != 0){
                    maxy++;
                    ct += cnt;
                }
                else{
                    maxy /= 2;
                    ct += cnt;
                }
            }
            fq[maxy] += cnt;
        }

        if (vec[0] % 2 != 0){
            map<ll, ll> fq1;
            ll ct2 = 0;

            for (auto const &p : fq3){
                ll val = p.first;
                ll count = p.second;

                if (val == vec[0]){
                    fq1[val + 1] += count; 
                    ct2 += count;   
                }
                else{
                    fq1[val] += count;
                }
            }

            while (fq1.size() > 1){
                ll maxy = fq1.rbegin()->first, cnt = fq1.rbegin()->second;
                fq1.erase(maxy);

                ll smax = fq1.rbegin()->first;

                while (maxy > smax){
                    if (maxy % 2 != 0){
                        maxy++;
                        ct2 += cnt;
                    }
                    else{
                        maxy /= 2;
                        ct2 += cnt;
                    }
                }
                fq1[maxy] += cnt;
            }

            ct = min(ct, ct2);
        }

        cout << ct << '\n';
    }
    return 0;
}