/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 * ref: https://leetcode.com/problems/burst-balloons/discuss/1659268/C%2B%2B-EASY-TO-UNDERSTAND-oror-All-Intuitions-step-by-step-with-detailed-explanations
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> new_nums(n, 1);
        int i = 1;
        for(int num : nums){
            new_nums[i++] = num;
        }
        //iterate from interval length from 2 to n
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                //select between left and right boundary (i, j)
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

