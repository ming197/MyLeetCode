/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            /* code */
            while(l < r && nums[l + 1] == nums[l]) l++;
            while(l < r && nums[r - 1] == nums[r]) r--;
            if(l >= r) break;
            
            int mid = l + (r - l >> 1);
            if(nums[mid] == target) return true;
            // 判断是 直线 还是 折线 
            if(nums[l] < nums[r]){ // 直线
                if(nums[mid] < target) l = mid + 1;
                else r = mid;
            }else { // 折线
                if(nums[mid] >= nums[l]){
                    if(target >= nums[l] && target < nums[mid]) r = mid;
                    else l = mid+1;
                }else{
                    if(target > nums[mid] && target <= nums[r]) l = mid + 1;
                    else r = mid;
                }
            }
        }
        return nums[l] == target;
    }
};
// @lc code=end

