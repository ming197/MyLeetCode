/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        bool flag = true;
        int idx = -1;
        while (flag)
        {
            /* code */
            if(++idx == strs[0].size()) break;
            char c = strs[0][idx];
            for(int i = 1; i < strs.size() && flag; i++){
                if(strs[i][idx] != c) {
                    flag = false;break;
                }
            }
            if(flag) {
                prefix += c;
            }
        }
        return prefix;
    }
};
// @lc code=end

