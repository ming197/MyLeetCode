/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        auto tupleCmp = [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, d1] = e1;
            auto&& [x2, y2, d2] = e2;
            return d1 > d2;
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> q(tupleCmp);
        q.emplace(0, 0, 0);

        vector<int> dist(m * n, INT_MAX);
        dist[0] = 0;
        vector<int> seen(m * n);

        while (!q.empty()) {
            auto [x, y, d] = q.top();
            q.pop();
            int id = x * n + y;
            if (seen[id]) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                break;
            }
            seen[id] = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && max(d, abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]) {
                    dist[nx * n + ny] = max(d, abs(heights[x][y] - heights[nx][ny]));
                    q.emplace(nx, ny, dist[nx * n + ny]);
                }
            }
        }
        
        return dist[m * n - 1];
    }
};

// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {

//         int m = heights.size(), n = heights[0].size();

//         int k = m * n;
//         int dx[4] = {1, -1, 0, 0};
//         int dy[4] = {0, 0, 1, -1};
//         auto cmp = [](const pair<int, long>& a, const pair<int, long>& b){
//             return a.second > b.second;
//         };

//         vector<priority_queue<pair<int, long>>> g(k);
//         vector<bool> visited(k, false);

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 int u = i * n + j;
//                 visited[u] = true;
//                 priority_queue<pair<int, long>, vector<pair<int, long>>, decltype(cmp)> q(cmp);
//                 for(int idx = 0; idx < 4; idx++){
//                     int next_i = i + dx[idx];
//                     int next_j = j + dy[idx];
//                     int v = next_i * n + next_j;
//                     if(next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
//                     // g[u][v] = g[v][u] = abs(heights[next_i][next_j] - heights[i][j]);
//                     q.push({v, abs(heights[i][j] - heights[next_i][next_j])});
//                 }
//             }
//         }

//         long inf = 1e10 + 10;

//         visited = vector<bool>(k, false);
//         vector<long> dis(k, inf);
//         dis[0] = 0;

//         for(int i = 0; i < k; i++){
//             int u = -1, min_ = inf;
//             for(int j = 0; j < k; j++){
//                 if(!visited[j] && dis[j] < min_){
//                     min_ = dis[j];
//                     u = j;
//                 }
//             }
//             if(u == -1) break;
//             visited[u] = true;
//             // for(int v = 0; v < k; v++){
//             //     if(!visited[v] && g[u][v] != -1 && dis[v] > max(dis[u], g[u][v])){
//             //         dis[v] = max(dis[u], g[u][v]);
//             //     }
//             // }

//         }    

//         return dis[k-1];
//     }
// };


int main(){
    Solution sol;
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    sol.minimumEffortPath(heights);
    return 0;
}
// @lc code=end

