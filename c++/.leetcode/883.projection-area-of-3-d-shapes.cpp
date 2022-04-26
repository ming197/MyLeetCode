/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = m * n;
        int cntZero = 0;
        for(int i = 0; i < m; i++){
            int h_max = -1;
            for(int& h : grid[i]){
                if(h == 0) cntZero++;
                h_max = max(h_max, h);
            }
            res += h_max;
        }

        for(int j = 0; j < n; j++){
            int h_max = -1;
            for(int i = 0; i < m; i++){
                h_max = max(h_max, grid[i][j]);
            }
            res += h_max;
        }
        return res - cntZero;
    }
};
// @lc code=end

