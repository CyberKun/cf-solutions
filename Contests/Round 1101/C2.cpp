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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, x, s;
        cin >> n >> x >> s;
        string ss;
        cin >> ss;

        ll ans = 0;
        ll lo = 0 , hi = 0;
        for(int i = 0 ; i < n ; i++) if(ss[i] == 'A') hi++;
        hi = min(hi,x);
        while(lo < hi) {
            ll mid = (lo+hi)/2;
            ll es = 0, is = x - mid, ai = mid;
            ll ct = 0;
            for (int j = 0; j < n; j++) {
                if (ss[j] == 'I' && is > 0) {
                    is--;
                    ct++;
                    es += s - 1;
                }
                else if (ss[j] == 'E' && es > 0) {
                    es--;
                    ct++;
                }
                else if (ss[j] == 'A'){
                    if (ai > 0){
                        ai--;
                        es += s - 1;
                        ct++;
                    }
                    else if (es > 0){
                        es--;
                        ct++;
                    }
                }
            }

            ll es1 = 0, is1 = x - mid - 1, ai1 = mid+1;
            ll ct1 = 0;
            for (int j = 0; j < n; j++)
            {
                if (ss[j] == 'I' && is1 > 0)
                {
                    is1--;
                    ct1++;
                    es1 += s - 1;
                }
                else if (ss[j] == 'E' && es1 > 0)
                {
                    es1--;
                    ct1++;
                }
                else if (ss[j] == 'A')
                {
                    if (ai1 > 0)
                    {
                        ai1--;
                        es1 += s - 1;
                        ct1++;
                    }
                    else if (es1 > 0)
                    {
                        es1--;
                        ct1++;
                    }
                }
            }
            if(ct < ct1) lo = mid+1;
            else hi = mid;
        }

        ll es = 0, is = x - lo, ai = lo;
        for (int j = 0; j < n; j++)
        {
            if (ss[j] == 'I' && is > 0)
            {
                is--;
                ans++;
                es += s - 1;
            }
            else if (ss[j] == 'E' && es > 0)
            {
                es--;
                ans++;
            }
            else if (ss[j] == 'A')
            {
                if (ai > 0)
                {
                    ai--;
                    es += s - 1;
                    ans++;
                }
                else if (es > 0)
                {
                    es--;
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
