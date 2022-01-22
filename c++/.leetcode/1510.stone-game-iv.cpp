/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!f[i - k * k]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

