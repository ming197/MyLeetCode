/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1, INT_MAX);
        f[0] = f[1] = 0;
        for(int i = 2; i <= n; i++){
            f[i] = min(f[i - 2] + cost[i - 2], f[i - 1] + cost[i - 1]);
        }
        return f[n];
    }
};

int main(){
    Solution sol;
    vector<int> cost = {1, 100};
    sol.minCostClimbingStairs(cost);
}
// @lc code=end

