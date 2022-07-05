/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int delta = 1e7;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] > delta) continue;
            if(arr[i] - arr[i - 1] < delta){
                res.clear();
                delta = arr[i] - arr[i - 1];
            }
            res.push_back({arr[i-1], arr[i]});
        }
        return res;
    }
};
// @lc code=end

