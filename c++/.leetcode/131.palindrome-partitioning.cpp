/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> f;
    vector<vector<string>> res;
    vector<string> tmp;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        f = vector<vector<bool>>(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            f[i][i] = true;
        }
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) f[i][i+1] = true;
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(s[i] == s[j]){
                    f[i][j] = f[i+1][j-1];
                }
            }
        }
        backtrack(s, n, 0, n);
        return res;
    }

    void backtrack(string& s, int& n, int startIdx, int strLen){
        if(strLen == 0){
            res.emplace_back(tmp);
            return;
        } 
        for(int l = 1; l <= strLen; l++){
            for(int i = startIdx; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(f[i][j]){
                    tmp.emplace_back(s.substr(i, l));
                    backtrack(s, n, j + 1, strLen - l);
                    tmp.pop_back();
                }
            }
        }
    }
};
// @lc code=end

