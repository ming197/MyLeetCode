/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(auto& x : accounts){
            res = max(res, accumulate(x.begin(), x.end(), 0));
        }
        return res;
    }
};
// @lc code=end

