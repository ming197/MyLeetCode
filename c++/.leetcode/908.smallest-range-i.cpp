/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = 1e4 + 10, max_val = 0;
        for(int& x : nums){
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        int res = (max_val - min_val) - 2 * k;
        return max(res, 0);
    }
};
// @lc code=end

