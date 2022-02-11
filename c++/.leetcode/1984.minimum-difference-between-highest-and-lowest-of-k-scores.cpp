/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = k - 1;
        int res = 1e5 + 10;
        while (j < nums.size())
        {
            /* code */
            res = min(res, nums[j] - nums[i]);
            i++;j++;
        }
        return res;
    }
};
// @lc code=end

