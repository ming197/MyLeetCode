/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            /* code */
            int mid = l + (r - l >> 1);
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
// @lc code=end

