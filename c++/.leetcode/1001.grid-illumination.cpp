/*
 * @lc app=leetcode id=1001 lang=cpp
 *
 * [1001] Grid Illumination
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int dx[9] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
    int dy[9] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        this->n = n;
        vector<int> rows(n, 0);
        vector<int> cols(n, 0);
        unordered_map<int, int> diagonal1, diagonal2;
        unordered_set<int> set;
        for(auto& lamp : lamps){
            int i = lamp[0], j = lamp[1];
            if(set.find(i * n + j) != set.end()) continue;
            rows[i]++;
            cols[j]++;
            diagonal1[i+j]++;
            diagonal2[i-j]++;
            set.insert(i*n+j);
        }
        vector<int> res(queries.size(), 0);
        int idx = 0;
        for(auto& q : queries){
            int i = q[0], j = q[1];
            if(rows[i] > 0 || cols[j] > 0 || diagonal1[i + j] > 0 || diagonal2[i - j] > 0) res[idx] = 1;
            shutDown(rows, cols, diagonal1, diagonal2, set, i, j);
            idx++;
        }
        return res;
    }

    void shutDown(vector<int>& rows, vector<int>& cols, unordered_map<int, int>& diagonal1, 
        unordered_map<int, int>& diagonal2, unordered_set<int>& set, int i, int j){
        for(int k = 0; k < 9; k++){
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= n) continue;
            if(set.find(next_i * n + next_j) != set.end()){
                rows[next_i]--;
                cols[next_j]--;
                diagonal1[next_i + next_j]--;
                diagonal2[next_i - next_j]--;
                set.erase(next_i * n + next_j);
            }
        }
    }
};
// @lc code=end

