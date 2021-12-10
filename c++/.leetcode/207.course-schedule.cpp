/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> g(numCourses);

        for(int i = 0; i < m; i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            inDegree[v]++;
            g[u].push_back(v);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        int num = 0;
        while (!q.empty())
        {
            /* code */
            int u = q.front();
            q.pop();
            num++;
            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(--inDegree[v] == 0){
                    q.push(v);
                }
            }
            g[u].clear();
        }
        return num == numCourses;
    }
};

// int main(){
//     vector<vector<int>> matrix = {{0, 1}};
//     Solution solution;
//     solution.canFinish(2, matrix);
//     return 0;
// }
// @lc code=end

