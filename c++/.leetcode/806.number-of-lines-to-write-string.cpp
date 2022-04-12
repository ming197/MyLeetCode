/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int res = 1;
        int width = 0;
        for(char& c: s){
            if(width + widths[c - 'a'] > 100){
                res++;
                width = widths[c - 'a'];
            }else width += widths[c - 'a'];
        }
        return {res, width};
    }
};
// @lc code=end

