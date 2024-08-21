#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> res;
        vector<ll> sum(n, 0);
        vector<int> left(n), prev(n);
        
        int l = 0, zeros = 0, ones = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] == '1') ones++;
            else zeros++;
            while (zeros > k && ones > k) {
                if (s[l] == '1') ones--;
                else zeros--;
                l++;
            }
            prev[r] = l;
        }

        sum[0] = 1;
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + i - prev[i] + 1;
        }

        for (auto &q : queries) {
            ll low = q[0], high = q[1];
            ll cur = 0, pos = high + 1;

            while (low <= high) {
                ll mid = (low + high) / 2;
                if (prev[mid] >= q[0]) {
                    pos = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (pos <= q[1]) {
                cur += sum[q[1]];
                if (pos > 0) cur -= sum[pos - 1];
            }

            cur += (pos - q[0]) * (pos - q[0] + 1) / 2;
            res.push_back(cur);
        }

        return res;
    }
};
