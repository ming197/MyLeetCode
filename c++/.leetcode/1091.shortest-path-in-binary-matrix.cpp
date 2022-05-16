/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        if(grid[0][0] == 1) return -1;
        q.push({0, 0});
        int depth = 0;
        while (!q.empty())
        {
            /* code */
            depth++;
            int size = q.size();
            while (size--)
            {
                auto [x, y] = q.front();
                q.pop();
                if(x == m - 1 && y == n - 1) return depth;
                /* code */
                for(int i = 0; i < 8; i++){
                    int next_x = x + dx[i];
                    int next_y = y + dy[i];
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y] || grid[next_x][next_y] == 1) continue;
                    visited[next_x][next_y] = 1;
                    q.push({next_x, next_y});
                    if(next_x == m - 1 && next_y == n - 1) return depth + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

