/*
 * @lc app=leetcode id=1725 lang=cpp
 *
 * [1725] Number Of Rectangles That Can Form The Largest Square
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = -1;
        for(auto& l_w : rectangles){
            int l = l_w[0], w = l_w[1];
            maxLen = max(maxLen, l > w ? w : l);
        }
        int res = 0;
        for(auto& l_w : rectangles){
            int l = l_w[0], w = l_w[1];
            res += min(l, w) == maxLen ? 1 : 0;
        }
        return res;
    }
};
// @lc code=end

