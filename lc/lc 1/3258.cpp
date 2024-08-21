#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int i = 0, res = 0;
        int cnt0 = 0, cnt1 = 0;
        int n = s.size();

        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }

            while (cnt0 > k && cnt1 > k) {
                if (s[i] == '0') {
                    cnt0--;
                } else {
                    cnt1--;
                }
                i++;
            }
            res += (j - i + 1);
        }
        return res;
    }
};


// class Solution {
// public:
//     int countKConstraintSubstrings(string s, int k) {
//         int ans = 0;
//         for(int i=0;i<s.size();i++){
//             int cnt1 = 0,cnt0 = 0;
//             for(int j=i;j<s.size();j++){
//                 if(s[j] == '1'){
//                     cnt1 += 1;
//                 }else{
//                     cnt0 += 1;
//                 }
//                 if(cnt1 <= k || cnt0 <= k){
//                     ans += 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };;