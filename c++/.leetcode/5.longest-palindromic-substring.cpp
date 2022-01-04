/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // {start, length}
        int res[2] = {0, 1};
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            f[i][i] = true;
        }
        for(int i = 0; i + 1 < n; i++){
            if(s[i] == s[i+1]){
                res[0] = i;
                res[1] = 2;
                f[i][i+1] = true;
            }
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(s[i] == s[j]){
                    if(f[i+1][j-1]){
                        f[i][j] = true;
                        if(l > res[1]){
                            res[0] = i;
                            res[1] = l;
                        }                        
                    }
                }
            }
        }
        return s.substr(res[0], res[1]);
    }
};

// int main(){
//     Solution solution;
//     string s = "babad";
//     solution.longestPalindrome(s);
//     return 0;
// }
// @lc code=end

