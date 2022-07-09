/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n, -1e9 - 10);
        f[0] = nums[0];
        deque<pair<int, int>> d_queue;
        d_queue.emplace_back(make_pair(f[0], 0));
        for(int i = 1; i < n; i++){
            int start = d_queue.front().second;
            if(i - start > k) d_queue.pop_front();
            int j = d_queue.front().second;
            f[i] = max(f[i], f[j] + nums[i]);
            while ( !d_queue.empty() && f[i] > d_queue.back().first)
            {
                /* code */
                d_queue.pop_back();
            }
            d_queue.emplace_back(make_pair(f[i], i));
        }
        return f[n - 1];
    }
};
// @lc code=end

