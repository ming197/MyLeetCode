/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0, 1};
        for(int i = 1; i < n; i++){
            int j = res.size() - 1;
            while (j >= 0)
            {
                /* code */
                res.emplace_back(res[j] + (1 << i));
                j--;
            }
        }
        return res;
    }
};
// @lc code=end

