/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        auto it = nums.begin();
        while (k--)
        {
            /* code */
            it++;
        }
        reverse(nums.begin(), it);
        reverse(it, nums.end());
    }
};
// @lc code=end

