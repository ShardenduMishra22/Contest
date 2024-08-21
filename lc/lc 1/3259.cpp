#include <bits/stdc++.h>
using namespace std;

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     typedef ll ll;
//     ll solve(vector<int>& edA, vector<int>& edB, int idx, int prev, vector<vector<ll>>& dp){
//         if (idx >= edA.size()) {
//             return 0;
//         }
//         if (dp[idx][prev] != -1) {
//             return dp[idx][prev];
//         }
//         ll mx = INT_MIN;
//         if (prev == 0) {
//             ll ans1 = edA[idx] + solve(edA, edB, idx + 1, 1, dp);
//             ll ans2 = edB[idx] + solve(edA, edB, idx + 1, 2, dp);
//             mx = max(ans1, ans2);
//         } else if (prev == 1) {
//             ll ans1 = edA[idx] + solve(edA, edB, idx + 1, 1, dp);
//             ll ans2 = solve(edA, edB, idx + 1, 2, dp);
//             mx = max(ans1, ans2);
//         } else {
//             ll ans1 = solve(edA, edB, idx + 1, 1, dp);
//             ll ans2 = edB[idx] + solve(edA, edB, idx + 1, 2, dp);
//             mx = max(ans1, ans2);
//         }
//         return dp[idx][prev] = mx;
//     }

//     ll maxEnergyBoost(vector<int>& edA, vector<int>& edB) {
//         vector<vector<ll>> dp(edA.size(), vector<ll>(3, -1));
//         return solve(edA, edB, 0, 0, dp);
//     }
// };

class Solution {
public:
    typedef long long ll;
    ll maxEnergyBoost(vector<int>& edA, vector<int>& edB) {
        int n = edA.size();

        ll maxBoost = 0;
        ll currA = 0, currB = 0;
        
        for (int i = 0; i < n; ++i) {
            ll newA = max(currA + edA[i], currB);
            ll newB = max(currB + edB[i], currA);
            
            currA = newA;
            currB = newB;
        }
        
        maxBoost = max(currA, currB);
        
        return maxBoost;
    }
};