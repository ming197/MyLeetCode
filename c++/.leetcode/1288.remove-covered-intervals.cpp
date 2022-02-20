/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> mergedIntervals;

        for(auto& interval : intervals){
            int l = interval[0], r = interval[1];
            if (!mergedIntervals.empty() && mergedIntervals.back()[1] >= r){
                // continue
            }else{
                mergedIntervals.emplace_back(interval);
            }
        }

        return mergedIntervals.size();
    }
};
// @lc code=end

