/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=s
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;
    int target;
    int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->n = candidates.size();
        backtrack(candidates, 0, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int s, int sum){
        if(sum == target){
            res.emplace_back(combination);
            return;
        }
        if(sum > target) return;
        if(s >= n) return;

        // push candidates[s]
        combination.emplace_back(candidates[s]);
        backtrack(candidates, s, sum + candidates[s]);
        combination.pop_back();

        // not push
        backtrack(candidates, s + 1, sum);
    }
};
// @lc code=end

