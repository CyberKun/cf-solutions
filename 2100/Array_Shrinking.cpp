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

// Global DP table
ll memo[1005][1005]; 
ll memo1[1005][1005][2];

ll solve(vector<ll>& arr, ll i, ll j , ll st , ll ed) {
    //Base Condition: A single matrix cannot be multiplied, or invalid bounds
    if (i >= j) {
        return 0;
    }

    
    //Memoization Check
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    ll min_ans = 0;
    
    // The 'k' Loop (Finding the optimal partition point)
    for (ll k = i; k <= j - 1; k++) {
        if(arr[k]!=arr[k+1])continue;
        arr[k]++;
        arr[k+1]++;
        ll left_subproblem1 = solve(arr, i, k-1 , arr[i] , arr[k-1]);
        ll right_subproblem1 = solve(arr, k+1 , j , arr[k+1] , arr[j]);
        ll left_subproblem2 = solve(arr, i, k - 2 , arr[i] , arr[k-2]);
        ll right_subproblem2 = solve(arr, k, j , arr[k] , arr[j]);
        ll temp_ans = max((left_subproblem1 + right_subproblem1),(left_subproblem2 + right_subproblem2))+1;
        min_ans = max(min_ans, temp_ans);
        if(temp_ans==min_ans){
            
        }
        arr[k]--;
        arr[k+1]--;
    }
    
    return memo[i][j] = (j-i+2) - min_ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        
        for (ll i = 0; i < n; i++) {
            cin >> vec[i];
        }
        
        // Reset the memo table for every test case
        memset(memo, -1, sizeof(memo));
        memset(memo1, -1, sizeof(memo1));

        // Initial call: 0 to n - 1
        ll ans = solve(vec, 0, n - 1 , vec[0] , vec[n-1]);
        
        cout << ans << "\n";
    }
    return 0;
}