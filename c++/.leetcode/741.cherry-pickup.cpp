/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                f[i][j] = -1;
            }
        }
        f[0][0] = grid[0][0];
        for(int j = 1; j < n; j++){
            if(grid[0][j] == -1) break;
            f[0][j] = f[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; i++){
            if(grid[i][0] == -1) break;
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        f[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                // left
                f[i][j] = (grid[i][j-1] == -1 ? -1 : f[i][j-1] + grid[i][j-1]);
                // up
                f[i][j] = max(f[i][j], grid[i-1][j] == -1 ? -1 : f[i-1][j] + grid[i-1][j]);
            }
        }
    }

    bool inGrid(int x, int y, int& m, int& n){
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }
};
// @lc code=end

