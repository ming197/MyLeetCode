/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int m = points.size();
        vector<vector<int>> g(m, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < i; j++){
                g[i][j] = g[j][i] = dis(points[i], points[j]);
            }
        }
        int inf = INT_MAX;
        vector<bool> visited(m, false);
        vector<int> dis(m, inf);
        dis[0] = 0;
        int res = 0;
        for(int k = 0; k < m; k++){
            int u = -1, min_dis = inf;
            for(int i = 0; i < m; i++){
                if(!visited[i] && dis[i] < min_dis){
                    u = i;
                    min_dis = dis[i];
                }
            }

            if(u == -1) break;
            res += dis[u];
            visited[u] = true;

            for(int v = 0; v < m; v++){
                if(!visited[v] && g[u][v] != inf && g[u][v] < dis[v]){
                    dis[v] = g[u][v];
                }
            }
        }

        return res;
    }

    int dis(vector<int>& a, vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
// @lc code=end

