/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0) return pos + 1;
            else nums[pos] *= -1;
        }
        return -1;
    }
};
// @lc code=end

