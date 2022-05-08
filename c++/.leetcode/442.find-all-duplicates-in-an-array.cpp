/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int x = (nums[i] - 1) % n ;
            nums[x] = nums[x] + n;
        }

        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] > 2 * n) res.emplace_back(i + 1);
        }
        return res;
    }
};
// @lc code=end

