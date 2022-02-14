/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    vector<int> nums;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        backtrack(0);
        return res;
    }

    void backtrack(int index){
        if(index == n){
            res.emplace_back(v);
            return;
        }

        // not insert nums[index]
        backtrack(index+1);

        // insert nums[index]
        v.emplace_back(nums[index]);
        backtrack(index+1);
        v.pop_back();
    }
};
// @lc code=end

