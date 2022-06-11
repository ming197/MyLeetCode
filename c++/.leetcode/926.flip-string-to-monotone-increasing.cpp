/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> f(2, vector<int>(n, n));
        f[0][0] = s[0] == '0' ? 0 : 1;
        f[1][0] = s[0] == '1' ? 0 : 1;
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                f[0][i] = f[0][i - 1];
                f[1][i] = min(f[0][i - 1], f[1][i - 1]) + 1;
            }else{
                f[0][i] = f[0][i - 1] + 1;
                f[1][i] = min(f[0][i - 1], f[1][i - 1]);
            }
        }
        return min(f[0][n - 1], f[1][n - 1]);
    }
};
// @lc code=end

