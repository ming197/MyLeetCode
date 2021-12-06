/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        vector<int> res(2, -1);
        // find first
        while (l < r)
        {
            /* code */
            int mid = l + ((r - l) >> 1);
            if(target > nums[mid]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(l == n || nums[l] != target) return res;
        res[0] = l;
        // find last
        l = 0;r = n-1;
        while (l < r)
        {
            /* code */
            int mid = l + ((r - l + 1) >> 1);
            if(target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        res[1] = l;
        return res;
    }
};
// @lc code=end

