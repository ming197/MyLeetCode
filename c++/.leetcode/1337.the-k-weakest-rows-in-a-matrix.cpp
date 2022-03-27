/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> mat2pair;
        int idx = 0;
        for(auto& row : mat){
            int cntOne = 0;
            for(int& x : row){
                if(x == 1) cntOne++;
                else break;
            }
            mat2pair.emplace_back(idx++, cntOne);
        } 

        sort(mat2pair.begin(), mat2pair.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        vector<int> res;

        for(int i = 0; i < k; i++){
            res.emplace_back(mat2pair[i].first);
        }

        return res;
    }
};
// @lc code=end

