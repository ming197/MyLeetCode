/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, -1);
        f[0] = 0;
        sort(coins.begin(), coins.end());
        for(int k = 1; k <= amount; k++){
            for(auto& x : coins){
                if(k < x) break;
                if(f[k - x] == -1) continue;
                f[k] = f[k] == -1 ? f[k - x] + 1 : min(f[k - x] + 1, f[k]);
            }
        }
        return f[amount];
    }
};
// @lc code=end

