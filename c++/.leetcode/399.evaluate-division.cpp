/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> g;
    // unordered_map<string, int> str2int;
    unordered_set<string> visited;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        int nodes = 0;
        for(int i = 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double cost = values[i];
            g[u][v] = cost;
            g[v][u] = 1.0 / cost;
            // if(str2int.find(u) == str2int.end()) str2int[u] = nodes++;
            // if(str2int.find(v) == str2int.end())  str2int[v] = nodes++;
        }
        int m = queries.size();
        vector<double> res;

        for(int i = 0; i < m; i++){
            string u = queries[i][0], v = queries[i][1];
            if(g.find(u) == g.end() || g.find(v) == g.end()){
                res.emplace_back(-1.0);continue;
            } 
            visited.clear();
            res.emplace_back(dfs(u, v, 1.0));
        }

        return res;
    }

    double dfs(string u, string end, double val){
        if(u == end) return val;
        visited.insert(u);
        for(auto& edge : g[u]){
            string v = edge.first;
            double cost = edge.second;
            if(visited.find(edge.first) == visited.end()){
                double res = dfs(v, end, val * cost);
                if(abs(res + 1.0) < (1e-9)) continue;;
                return res;
            }
        }
        return -1.0;
    }
};
// @lc code=end

