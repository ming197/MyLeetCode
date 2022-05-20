# 并查集

[水位上升的泳池中游泳](https://leetcode.cn/problems/swim-in-rising-water/solution/shui-wei-shang-sheng-de-yong-chi-zhong-y-xm9i/)

```c++
class Solution {
public:
    int find(vector<int>& f, int x) {
        if (f[x] == x) {
            return x;
        }
        int fa = find(f, f[x]);
        f[x] = fa;
        return fa;
    }

    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n * n);
        for (int i = 0; i < n * n; i++) {
            f[i] = i;
        }

        vector<pair<int, int>> idx(n * n); // 存储每个平台高度对应的位置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                idx[grid[i][j]] = make_pair(i, j);
            }
        }

        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        for (int threshold = 0; threshold < n * n; threshold++) {
            auto [i, j] = idx[threshold];
            for (const auto [di, dj]: directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] <= threshold) {
                    merge(f, i * n + j, ni * n + nj);
                }
            }
            if (find(f, 0) == find(f, n * n - 1)) {
                return threshold;
            }
        }
        return -1; // cannot happen
    }
};
```