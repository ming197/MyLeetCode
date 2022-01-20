/*
 * @lc app=leetcode id=2029 lang=cpp
 *
 * [2029] Stone Game IX
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};
        for(int& x : stones){
            int i = x % 3;
            f[i]++;
        }
        if(f[0] % 2 == 0){
            return f[1] >= 1 && f[2] >= 1;
        }
        return abs(f[1] - f[2]) > 2;
    }
};
// @lc code=end

