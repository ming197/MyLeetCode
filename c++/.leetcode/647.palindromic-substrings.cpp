/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j - i < 2) f[i][j] = (s[i] == s[j]);
                else{
                    f[i][j] = (s[i] == s[j] ? f[i + 1][j - 1] : false);
                }
                res += f[i][j] ? 1 : 0;
            }
        }
        return res;
    }
};
// @lc code=end

