#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> d_row{-1, 1, 0, 0};
    vector<int> d_col{0, 0, -1, 1};
    vector<vector<bool>> visited;
    int res = INT_MAX;
    int m;
    int n;
    unordered_map<char, int> char2int;
    vector<string> matrix;
    vector<int> end;
    vector<vector<int>> f;
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        this->matrix = matrix;
        this->end = end;
        m = matrix.size();
        n = matrix[0].size();
        visited = vector(m, vector<bool>(n, false));
        f = vector(m, vector<int>(n, INT_MAX));
        char2int['^'] = 0;
        char2int['v'] = 1;
        char2int['<'] = 2;
        char2int['>'] = 3;

        dfs(start[0], start[1], 0);
        return res;
    }

    void dfs(int i, int j, int ops){
        if(i == end[0] && j == end[1]){
            res = min(res, ops);
            return;
        }
        if(ops > f[i][j]) return;
        f[i][j] = ops;

        char c = matrix[i][j];
        visited[i][j] = true;
        int next_i = i + d_row[char2int[c]];
        int next_j = j + d_col[char2int[c]];

        if(next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || visited[next_i][next_j]){
            for(int k = 0; k < 4; k++){
                if(k == char2int[c]) continue;
                next_i = i + d_row[k];
                next_j = j + d_col[k];
                if(next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || visited[next_i][next_j]) continue;
                dfs(next_i, next_j, ops + 1);
            }
        }else{
            dfs(next_i, next_j, ops);
        }
        visited[i][j] = false;
    }
};


int main(){
    Solution solution;
    vector<int> time{2, 3, 2};
    vector<vector<int>> fruits{{0, 2}, {1, 4}, {2, 1}};
    int limit = 3;
    
    return 0;
}