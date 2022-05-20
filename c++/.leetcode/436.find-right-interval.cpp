/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts;
        unordered_map<int, int> val2Idx;
        int idx = 0;
        for(auto& interval : intervals){
            starts.emplace_back(interval[0]);
            val2Idx[starts.back()] = idx++;
        }
        sort(starts.begin(), starts.end());
        vector<int> res;

        for(auto& interval : intervals){
            int end = interval[1];
            int l = 0, r = n - 1;
            while (l < r){
                /* code */
                int mid = l + (r - l >> 1);
                if(starts[mid] >= end){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            res.emplace_back(starts[l] >= end ? val2Idx[starts[l]] : -1);
        }

        return res;
    }
};
// @lc code=end

