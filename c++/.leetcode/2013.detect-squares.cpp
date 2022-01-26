/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> cntx;
    
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        cntx[x][y]++;
    }
    
    int count(vector<int> point) {
        int x0 = point[0];
        int y0 = point[1];
        int ans = 0;
        
        for (auto yc : cntx[x0]) {
            if (yc.first == y0) continue;
            int x1 = x0;
            int y1 = yc.first;
            int edge = abs(y1 - y0);
            ans += yc.second * (cntx[x0+edge][y1] * cntx[x0+edge][y0] + cntx[x0-edge][y1] * cntx[x0-edge][y0]);
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

