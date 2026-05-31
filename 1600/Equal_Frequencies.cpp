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

vector<ll> factors(ll n) {
    vector<ll> f;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if(i >= (n/26))f.push_back(i);
            if (i != n / i && (n/i >= (n/26))) f.push_back(n / i);
        }
    }
    sort(f.begin(), f.end());
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> facts = factors(n);
        string l = s;
        sort(l.begin(),l.end());
        vector<ll>freqs;
        ll ct = 1;
        for(int i = 1 ; i < n ; i++) {
            if(l[i] == l[i-1]) ct++;
            else {
                freqs.push_back(ct);
                ct=1;
            }
        }
        freqs.push_back(ct);
        sort(freqs.begin(),freqs.end());

        if(freqs[0] == freqs[freqs.size()-1]) {
            cout << 0 << '\n';
            cout << s << '\n';
            continue;
        }

        if(facts.empty()) {
            ll a1 = 0 , a2 = 0;
            for(int i = 0 ; i < freqs.size() ; i++) a1 += freqs[i]-1;
            for(int i = 0 ; i < freqs.size()-1 ; i++) a2 += freqs[i];
            if(s.size() > 26 || a2 <= a1) {
                cout << a2 << '\n';
                vector<pair<char, ll>> pairfreq;
                ll ct2 = 1;
                for (int i = 1; i < n; i++) {
                    if (l[i] == l[i - 1])
                        ct2++;
                    else {
                        pairfreq.push_back({l[i - 1], (ct2)});
                        ct2 = 1;
                    }
                }
                pairfreq.push_back({l[n - 1], (ct2)});
                sort(pairfreq.begin(), pairfreq.end(), [](const pair<char, ll> &a, const pair<char, ll> &b)
                     {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first; });
                reverse(pairfreq.begin(), pairfreq.end());
                char c = pairfreq[0].first;
                for(int i = 0 ; i < n ; i++) cout << c;
                cout << '\n';
            }
            else {
                cout << a1 << '\n';
                vector<bool>notpr(27,true);
                for(int i = 0 ; i < n ; i++) {
                    notpr[s[i]-'a'] = false;
                }
                map<char,ll>fq;
                for(int i = 0 ; i < n ; i++) {
                    if(!fq[s[i]]) {
                        cout << s[i];
                        fq[s[i]]++;
                    }
                    else {
                        for (int j = 0; j < 26; j++) { 
                            if (notpr[j]) {
                                notpr[j] = false;
                                cout << char('a' + j);
                                break;
                            }
                        }
                    }
                }
                cout << '\n';
            }
            continue;
        }

        vector<pair<ll,ll>> req(facts.size());
        for(int i = 0 ; i < facts.size() ; i++) {
            vector<ll> rems;
            for(int j = 0 ; j < freqs.size() ; j++) {
                rems.push_back(freqs[j]);
            }
            sort(rems.begin(),rems.end());
            reverse(rems.begin(),rems.end());
            ll cnt = 0 , avl = 0;
            for(int j = 0 , k = rems.size()-1 ; j <= k ;) {
                if(rems[j] + avl >= facts[i]) {
                    avl -= (facts[i] - rems[j]);
                    j++;
                }
                else {
                    avl += rems[k];
                    cnt += rems[k];
                    k--;
                }
            }
            req[i] = {cnt,facts[i]};
        }
        sort(req.begin(),req.end());
        cout << req[0].first << '\n';

        if(req[0].first == 0) {
            cout << s << '\n';
            continue;
        }

        vector<pair<char,ll>> pairfreq;
        ll ct1 = 1;
        for (int i = 1; i < n; i++) {
            if (l[i] == l[i - 1]) ct1++;
            else {
                pairfreq.push_back({l[i-1],(ct1)});
                ct1 = 1;
            }
        }
        pairfreq.push_back({l[n-1],(ct1)});
        sort(pairfreq.begin(), pairfreq.end(), [](const pair<char, ll> &a, const pair<char, ll> &b)
             {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first; });
        reverse(pairfreq.begin(),pairfreq.end());
        ll cnt1 = 0, avl1 = 0;
        map<char,ll> kill;
        vector<pair<char,ll>>needed;
        for (int j = 0, k = pairfreq.size() - 1; j <= k;)
        {
            if (pairfreq[j].second + avl1 >= req[0].second){
                needed.push_back({pairfreq[j].first, req[0].second - pairfreq[j].second});
                avl1 -= (req[0].second - pairfreq[j].second);
                j++;
            }
            else{
                avl1 += pairfreq[k].second;
                cnt1 += pairfreq[k].second;
                kill[pairfreq[k].first] = pairfreq[k].second;
                k--;
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if (kill[s[i]]) {
                kill[s[i]]--;
                s[i] = needed[needed.size() - 1].first;
                needed[needed.size() - 1].second--;
                if (needed[needed.size() - 1].second == 0) needed.pop_back();
            }
        }
        cout << s << '\n';
    }
    return 0;
}
