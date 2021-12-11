/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int prev = nums[0];
        // int curr = nums[0];
        int res = prev;
        for(int i = 1; i < nums.size(); i++){
            prev = max(0, prev) + nums[i];
            res = max(res, prev);
        }
        return res;
    }
};
// @lc code=end

