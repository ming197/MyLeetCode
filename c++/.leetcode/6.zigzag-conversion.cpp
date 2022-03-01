/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for(auto c : s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows - 1)  goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ans;
        for(auto row : rows) ans += row;
        return ans;
    }
};
// @lc code=end

