/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class Solution {
private:
    vector<int> ds;
    int m, n;
public:
    int Find(int x) {
        return ds[x]==-1?x:ds[x] = Find(ds[x]);
    }
    
    void Union(vector<vector<int>>& grid, int i, int j, int ni, int nj, int t) {
        if(i<0 || i>=m) return;
        if(ni<0 || ni>=m) return;
        if(j<0 || j>=n) return;
        if(nj<0 || nj>=n) return ;
        
        if(grid[i][j]<=t && grid[ni][nj]<=t) {
            
            int parent_i = Find(i*n+j);
            int parent_ni = Find(ni*n+nj);
            if(parent_i != parent_ni) {
                ds[parent_ni] = parent_i;
            }
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ds = vector<int>(m*n, -1);
        
        // elevation to array(pos1, pos2...)
        unordered_map<int, vector<pair<int,int>>> s;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                s[grid[i][j]].push_back({i,j});
            }
        }
        
        int t = 0;
        while(true) {
            // connect all blocks with water level = t
            vector<pair<int,int>>& blocks = s[t];
            if(blocks.size()>0) {
                for(auto &it : blocks) {
                    // union neighbor
                    int i = it.first, j = it.second;
                    Union(grid, i, j, i+1, j, t);
                    Union(grid, i, j, i-1, j, t);
                    Union(grid, i, j, i, j+1, t);
                    Union(grid, i, j, i, j-1, t);
                }
                // check if we have reached final pos
                int ps = Find(0);
                int pe = Find(m*n-1);
                if(ps==pe)
                    break;
            }
            ++t;
        }
        return t;
    }
};
// @lc code=end

