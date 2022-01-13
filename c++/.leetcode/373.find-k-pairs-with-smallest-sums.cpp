/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y){
            return nums1[x.first] + nums2[x.second] > nums1[y.first] + nums2[y.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for(int i = 0; i < min(m, k); i++){
           q.emplace(i, 0);
        }
        vector<vector<int>> res;
        while (k-- > 0 && !q.empty())
        {
            /* code */
            auto [x, y] = q.top();
            q.pop();
            res.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if(y + 1 < n){
                q.emplace(x, y + 1);
            }
        }
        return res;
    }
};
// @lc code=end

