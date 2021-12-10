/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '0';
        for(int k = 0; k < 4; k++){
            int next_i = dir[k][0] + i;
            int next_j = dir[k][1] + j;
            if(next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || grid[next_i][next_j] == '0') continue;
            dfs(grid, next_i, next_j);
        }
    }
};
// @lc code=end

