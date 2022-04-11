/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0) return grid;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(k; k > 0; k--){
            
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n - 1; j++){
                    res[i][j + 1] = grid[i][j];
                }
            }

            for(int i = 0; i < m - 1; i++){
                res[i + 1][0] = grid[i][n-1];
            }

            res[0][0] = grid[m-1][n-1];

            grid = res;
        }
        return res;
    }
};
// @lc code=end

