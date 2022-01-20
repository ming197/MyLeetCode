// /*
//  * @lc app=leetcode id=1345 lang=cpp
//  *
//  * [1345] Jump Game IV
//  */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    unordered_map<int, vector<int>> valToIdx;
    vector<bool> visited;
    int minJumps(vector<int>& arr) {
        n = arr.size();
        if(n == 1) return 0;
        int i = 0;
        for(int& x : arr){
            valToIdx[x].emplace_back(i++);
        }
        queue<int> q;
        q.push(0);
        visited = vector<bool>(n, false);
        visited[0] = true;
        int res = 0;
        while (!q.empty())
        {
            /* code */
            res++;
            int k = q.size();
            for( i = 0; i < k; i++){
                int idx = q.front();
                q.pop();
                if(idx - 1 >= 0 && !visited[idx-1]){
                    q.push(idx - 1);
                    visited[idx - 1] = true;
                    if(idx - 1 == n - 1) return res;
                }
                if(idx + 1 < n && !visited[idx + 1]){
                    q.push(idx + 1);
                    visited[idx + 1] = true;
                    if(idx + 1 == n - 1) return res;
                }
                for(int& x : valToIdx[arr[idx]]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
                        if(x == n - 1) return res;
                    }
                }
                valToIdx[arr[idx]].clear();
            }
        }
        return res;
    }

};
// @lc code=end

