/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         auto cmp = [](pair<int, int> x, pair<int, int> y){
            return x.second < y.second; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int i = 0;
        for(auto& point : points){
            int dis = point[0] * point[0] + point[1] * point[1];
            if(q.size() < k) {
                q.push({i, dis});
            }else if (dis < q.top().second){
                q.pop();
                q.push({i, dis});
            }
            i++;
        }
        vector<vector<int>> res;
        while (!q.empty())
        {
            res.push_back(points[q.top().first]);
            q.pop();
        }
        return res;
    }
};
// @lc code=end

