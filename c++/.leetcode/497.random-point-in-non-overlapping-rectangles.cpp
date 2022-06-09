/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> areas;
    int sum = 0;
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for(auto& rect : rects){
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            areas.emplace_back(sum);
        }
    }
    
    vector<int> pick() {
        int k = rand() % sum  + 1;
        int l = 0, r = areas.size() - 1;
        while (l < r)
        {
            /* code */
            int mid = l + (r - l >> 1);
            if(areas[mid] >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        int x = rand() % (rects[l][2] - rects[l][0] + 1) + rects[l][0];
        int y = rand() % (rects[l][3] - rects[l][1] + 1) + rects[l][1];
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

