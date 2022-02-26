/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        int i = 1;
        int min_ = nums[0];
        while (i < n){
            /* code */
            res = max(res, nums[i] - min_ > 0 ? nums[i] - min_ : -1);
            if(nums[i] < min_){
                min_ = nums[i];
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

