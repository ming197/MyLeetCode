/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int l = 0, r = -1;
        int cnt_zero = 0;
        while(++r < n){
            if(nums[r] == 0){
                cnt_zero++;
                while(l <= r && cnt_zero > k){
                    if(nums[l] == 0) cnt_zero--;
                    l++;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end

