/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y){
            if(x[0] != y[0]) return x[0] < y[0];
            return x[1] < y[1];
        });
        int res = 0;
        int pos = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > pos){
                res++;
                pos = points[i][1];
            }else if(points[i][1] < pos){
                pos = points[i][1];
            }
        }
        res++;
        return res;
    }
};
// @lc code=end

