/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> cnt;
        for (int j = 0; j < n; ++j) {
            res += (cnt.count(nums[j] - k) ? cnt[nums[j] - k] : 0);
            res += (cnt.count(nums[j] + k) ? cnt[nums[j] + k] : 0);
            ++cnt[nums[j]];
        }
        return res;
    }
};
// @lc code=end

