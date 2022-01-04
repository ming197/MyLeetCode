/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash_table(3, -1);
        int res = 0;
        int l = 0, r = -1;
        while (++r < s.size())
        {
            /* code */
            hash_table[s[r] - 'a'] = r;
            while (l < r && hash_table[0] >= l && hash_table[1] >= l && hash_table[2] >= l)
            {
                /* code */
                res += (s.size() - r);
                l++;
            }
        }
        return res;
        
    }
};
// @lc code=end

