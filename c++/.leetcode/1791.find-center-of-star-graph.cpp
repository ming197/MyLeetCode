/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> map;
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            map[u]++;
            if(map[u] > 1) return u;
            map[v]++;
            if(map[v] > 1) return v;
        }
        return 0;
    }
};
// @lc code=end

