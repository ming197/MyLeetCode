/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        for(int i = 0; i < m; i++){
            // find min
            int col = 0;
            for(int j = 1; j < n; j++){
                if(matrix[i][col] > matrix[i][j]){
                    col = j;
                }
            }
            // if max in col
            bool flag = true;
            for(int row = 0; row < m && flag; row++){
                if(matrix[row][col] > matrix[i][col]){
                    flag = false;
                } 
            }
            if(flag) res.emplace_back(matrix[i][col]);
        }
        return res;
    }
};
// @lc code=end

