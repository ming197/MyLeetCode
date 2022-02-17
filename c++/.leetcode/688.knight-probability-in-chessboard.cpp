/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int dx[8] = {1, 2, -1, -2, 1, 2, -1, -2};
        int dy[8] = {2, 1, 2, 1, -2, -1, -2, -1};
        // f[i][j][p]: beign from (i, j), the probility in range, at step k
        double f[n][n][k+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                f[i][j][0] = 1.0;
                for(int p = 1; p <= k; p++) f[i][j][p] = 0;
            }
        }
        for(int p = 1; p <= k; p++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(int idx = 0; idx < 8; idx++){
                        int nx = i + dx[idx];
                        int ny = j + dy[idx];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        f[i][j][p] += f[nx][ny][p - 1] / 8;
                    }
                }
            }
        }
        return f[row][column][k];
    }
};
// @lc code=end

