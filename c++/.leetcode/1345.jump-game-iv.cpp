/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<int> f;
    unordered_map<int, vector<int>> valToIdx;
    vector<bool> visited;
    int minJumps(vector<int>& arr) {
        this->n = arr.size();
        for(int i = 0; i < this->n; i++){
            int x = arr[i];
            if(valToIdx.find(x) == valToIdx.end()){
                valToIdx[x] = vector<int>(1, i);
            }else valToIdx[x].emplace_back(i);
        }
        
        f = vector<int>(this->n, -1);
        visited = vector<bool>(this->n, false);
        f[this->n - 1] = 0;
        int res = dfs(arr, 0);
        return res;
    }
    int dfs(vector<int>& arr, int pos){
        if(pos == n - 1){
            return 0;
        }
        visited[pos] = true;
        int res = 1e5;
        if(pos - 1 >= 0 && !visited[pos - 1]){
            if(f[pos - 1] != -1) res = min(res, 1 + f[pos-1]);
            else res = min(res, 1 + dfs(arr, pos - 1));
        } 
        if(pos + 1 < this->n && !visited[pos + 1]){
            if(f[pos + 1] != -1) res = min(res, 1 + f[pos+1]);
            else res = min(res, 1 + dfs(arr, pos + 1));
        } 
        for(int& x : valToIdx[arr[pos]]){
            if(x != pos && !visited[x]){
                if(f[x] != -1) res = min(res, 1 + f[x]);
                else res = min(res, 1 + dfs(arr ,x));
            }
        }
        f[pos] = res;
        visited[pos] = false;
        return res;
    }
};
// @lc code=end

