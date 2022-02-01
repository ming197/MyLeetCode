/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int in = prices[0];
        int res = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] < in){
                in = prices[i];
            }else{
                res = max(res, prices[i] - in);
            }
        }
        return res;
    }
};
// @lc code=end

