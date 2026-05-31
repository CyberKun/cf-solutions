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

vector<ll> factors(ll n){
    vector<ll> f;
    for (ll i = 1; i * i <= n; i++){
        if (n % i == 0){
            if (i*26 >= n) f.push_back(i);
            if (i != n / i && ((n / i)*26 >= n)) f.push_back(n / i);
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
        // for(int i = 0 ; i < facts.size() ; i++) cout << facts[i] << ' ';
        // cout << '\n';
        string l = s;
        sort(l.begin(), l.end());
        map<char,ll> freq;

        vector<pair<ll , char>> pairfreq;
        ll ct = 1;
        for (int i = 1; i < n; i++){
            if (l[i] == l[i - 1]) ct++;
            else{
                freq[l[i-1]] = ct;
                pairfreq.push_back({ct, l[i-1]});
                ct = 1;
            }
        }
        pairfreq.push_back({ct , l[n-1]});
        freq[l[n-1]]=ct;
        sort(pairfreq.begin() , pairfreq.end());
        reverse(pairfreq.begin() , pairfreq.end());
        // for(int i = 0 ; i < pairfreq.size() ; i++) cout << pairfreq[i].first << ' ' << pairfreq[i].second << '\n';

        vector<pair<ll, ll>> req(facts.size());
        for (int i = 0; i < facts.size(); i++){
            ll cnt = 0, avl = 0;
            for (int j = 0, k = pairfreq.size() - 1; j <= k;){
                if(pairfreq[j].first > facts[i]) {
                    avl += (pairfreq[j].first - facts[i]);
                    cnt += (pairfreq[j].first - facts[i]);
                    j++;
                }
                else if (pairfreq[j].first + avl >= facts[i]){
                    avl -= (facts[i] - pairfreq[j].first);
                    j++;
                }
                else{
                    avl += pairfreq[k].first;
                    cnt += pairfreq[k].first;
                    k--;
                }
            }
            // cout << cnt << ' ' << facts[i] << '\n';
            req[i] = {cnt, facts[i]};
        }
        sort(req.begin(), req.end());
        cout << req[0].first << '\n';
        // ll tar = req[0].second;
        // vector<pair<char,ll>> need;
        // vector<bool> notpr(26,true);
        // for(int i = 0 ; i < pairfreq.size() ; i++) {
        //     notpr[pairfreq[i].second - 'a'] = false;
        //     if(pairfreq[i].first < tar) need.push_back({pairfreq[i].second , tar - pairfreq[i].first});
        // }
        // for(int i = 0 ; i < 26 ; i++) {
        //     if(notpr[i]) need.push_back({char('a'+i),tar});
        // }
        // reverse(need.begin(),need.end());

        // for(int i = 0 ; i < n ; i++) {
        //     if(freq[s[i]] == tar) cout << s[i];
        //     else if(freq[s[i]] > tar) {
        //         cout << need[need.size()-1].first;
        //         need[need.size()-1].second--;
        //         if(!need[need.size()-1].second) need.pop_back();
        //         freq[s[i]]--;
        //     }
        //     else {

        //     }
        // }
        // cout << '\n';
        ll tar = req[0].second , num = n / tar;
        map<char, ll> change;
        vector<pair<char, ll>> need;

        for (int i = 0; i < pairfreq.size(); i++){
            if (i < num){
                if (pairfreq[i].first > tar)change[pairfreq[i].second] = pairfreq[i].first - tar;
                else if (pairfreq[i].first < tar)need.push_back({pairfreq[i].second, tar - pairfreq[i].first});
            }
            else change[pairfreq[i].second] = pairfreq[i].first;
        }

        if (pairfreq.size() < num) {
            vector<bool> used(26, false);
            for (int i = 0; i < pairfreq.size(); i++){
                used[pairfreq[i].second - 'a'] = true;
            }
            ll nuu = num - pairfreq.size();
            for (int i = 0; i < 26 && nuu > 0; i++){
                if (!used[i]){
                    need.push_back({char('a' + i), tar});
                    nuu--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (change[s[i]] > 0) {
                change[s[i]]--;          
                s[i] = need.back().first; 
                need.back().second--;
                if (need.back().second == 0) need.pop_back();
            }
        }
        cout << s << '\n';
    }
    return 0;
}
