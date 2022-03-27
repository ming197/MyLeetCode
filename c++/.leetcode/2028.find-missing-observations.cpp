/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        sum -= accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> res;
        if(sum < n || sum > 6 * n) return res;
        int x = sum / n;
        int left = sum - x * n;
        while (n--)
        {
            /* code */
            res.emplace_back(x);
        }
        while (left--)
        {
            /* code */
            res[left]++;
        }
        
        return res;
    }
};
// @lc code=end

