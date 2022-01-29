/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j]){
                    q.emplace(i, j);
                    visited[i][j] = true;
                    height[i][j] = 0;
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int h = 1;
        while (!q.empty())
        {
            /* code */
            int k = q.size();
            while (k--)
            {
                /* code */
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int next_x = x + dx[i];
                    int next_y = y + dy[i];
                    if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !visited[next_x][next_y]){
                        visited[next_x][next_y] = true;
                        height[next_x][next_y] = h;
                        q.emplace(next_x, next_y);
                    }
                }
            }
            h++;
        }
        return height;
    }
};
// @lc code=end

