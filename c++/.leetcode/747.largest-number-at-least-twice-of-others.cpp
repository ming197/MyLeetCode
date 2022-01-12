/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIdx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i != maxIdx){
                if(2 * nums[i] >= nums[maxIdx]) return -1;
            }
        }
        return maxIdx;
    }
};
// @lc code=end

