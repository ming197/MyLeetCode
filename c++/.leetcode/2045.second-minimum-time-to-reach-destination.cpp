/*
 * @lc app=leetcode id=2045 lang=cpp
 *
 * [2045] Second Minimum Time to Reach Destination
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> g_adj[n+1];
        for(int i = 1; i <= n; i++){
            g_adj[i] = vector<int>();
        }
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            g_adj[u].emplace_back(v);
        }
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int t = 0;
        int cnt = 0;
        while (!q.empty())
        {
            /* code */
            int size = q.size();
            for(int i = 0; i < size; i++){
                int u = q.front();
                if(u == n){
                    if(cnt == 0) cnt++;
                    else return t;
                } 
                if(((t / change) & 1) == 1){ // red
                    if((t / change) * change + change < t + time){
                        t = (t / change) * change + change;
                    }else{
                        q.pop();q.emplace(u);
                        continue;
                    }
                }
                q.pop();
                
                for(int& v : g_adj[u]){
                    if(!visited[v]){
                        q.emplace(v);
                        visited[u] = true;
                    }
                }
            }
            t += time;
        }
        return -1;
    }
};
// @lc code=end

