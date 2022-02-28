/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int start = nums[0];
        int curr = start;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(curr + 1 != nums[i]){
                res.emplace_back(to_string(start) + "->" + to_string(curr));
                start = curr = nums[i];
            }else{
                curr = nums[i];
            }
        }
        if(curr != start) res.emplace_back(to_string(start) + "->" + to_string(curr));
        else res.emplace_back(to_string(start));
        return res;
    }
};
// @lc code=end

