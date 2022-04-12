/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> origin(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                origin[i][j] = board[i][j];
            }
        }

        vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, 1, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int lives = 0;
                for(int k = 0; k < 8; k++){
                    int next_i = i + dx[k];
                    int next_j = j + dy[k];
                    if(next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                    if(origin[next_i][next_j] == 1){
                        lives++;
                    }
                }

                if(lives < 2) board[i][j] = 0;
                else if(lives == 2 || lives == 3) {
                    if(board[i][j] == 0 && lives == 2) board[i][j] = 0;
                    else board[i][j] = 1;
                }else{
                    board[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end

