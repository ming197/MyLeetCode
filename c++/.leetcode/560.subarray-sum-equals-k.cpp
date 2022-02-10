/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int preSum = 0;
        int res = 0;
        for(int& x : nums){
            preSum += x;
            map[preSum]++;
            res += map[preSum - k];
        }
        return res;
    }
};
// @lc code=end

