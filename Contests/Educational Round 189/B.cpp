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
        string s;
        cin >> s;
        int ct = 0;
        for(int i = 0 ; i < s.size()-1 ; i++) {
            if(s[i] == s[i+1]) ct++;
        }
        if(ct == 1) cout << "YES\n";
        else if(ct > 2) cout << "NO\n";
        else {
            ll st = -1 , ed = -1;
            for(int i = 1 ; i < s.size() ; i++) {
                if(s[i] == s[i-1]) {
                    st=i;
                    break;
                }
            }
            for (int i = st+1; i < s.size()-1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    ed = i;
                    break;
                }
            }
            string s1 = s , s2 = s;
            reverse(s1.begin()+st,s1.begin()+ed+1);
            for(int i = st ; i <= ed ; i++) {
                if(s2[i] == 'a') s2[i] = 'b';
                else s2[i] = 'a';
            }
            reverse(s2.begin() + st, s2.begin() + ed+1);
            if(s == s1 || s == s2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
