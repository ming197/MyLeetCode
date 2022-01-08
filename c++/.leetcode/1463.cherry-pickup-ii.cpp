/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
public:
    int dy[3] = {-1, 0, 1};
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    f[i][j][k] = -1;
                }
            }
        }
        f[0][0][n-1] = grid[0][0] + grid[0][n-1];
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                for(int k = n - 1; k >= 0; k--){
                    if(f[i][j][k] >= 0){
                        int f_prev = f[i][j][k];
                        for(int y1 : dy){
                            int col1 = j + y1;
                            if(col1 < 0 || col1 >= n) continue;
                            for(int y2 : dy){
                                int col2 = k + y2;
                                if(col2 < 0 || col2 >= n) continue;
                                f[i + 1][col1][col2] = max(f[i + 1][col1][col2], f_prev + (col1 == col2 ? grid[i+1][col1] : grid[i+1][col1] + grid[i+1][col2]));
                            }
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res = max(res, f[m-1][j][k]);
            }
        }
        return res;
    }
};
// @lc code=end

