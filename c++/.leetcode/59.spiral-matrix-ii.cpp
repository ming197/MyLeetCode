/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int i = 0, j = -1;
        int k = 0;
        int cnt  = 0;
        int total = n * n;
        vector<int> dj = {1, 0, -1, 0};
        vector<int> di = {0, 1, 0, -1};
        while (cnt < total)
        {
            /* code */
            int next_i = i + di[k];
            int next_j = j + dj[k];
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= n || visited[next_i][next_j]){
                k = (k + 1) % 4;
                next_i = i + di[k];
                next_j = j + dj[k];
            }
            i = next_i; j = next_j;
            visited[i][j] = true;
            matrix[i][j] = (++cnt);
        }
        return matrix;
    }
};
// @lc code=end

