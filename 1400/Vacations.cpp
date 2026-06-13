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

    ll n;
    cin >> n;
    vector<int>vec(n);
    for(int i = 0 ; i < n ; i++) cin >> vec[i];

    int ctr = 0 , ctg = 0 , ctc = 0;
    for(int i = 0 ; i < n ; i++) {
        if(vec[i]==0) {
            ctr++;
            ctg=0;
            ctc=0;
        }
        else if(vec[i]==1) {
            if(ctc==0) {
                ctc++;
                ctg=0;
            }
            else {
                ctr++;
                ctc=0;
                ctg=0;
            }
        }
        else if(vec[i]==2) {
            if(ctg==0) {
                ctg++;
                ctc=0;
            }
            else {
                ctr++;
                ctc=0;
                ctg=0;
            }
        }
        else {
            if(ctc==0&&ctg==0) continue;
            else if(ctc==1) {
                ctc=0;
                ctg=1;
            }
            else {
                ctg=0;
                ctc=1;
            }
        }
    }
    cout << ctr << '\n';
    return 0;
}
