/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size(), i = 0;
        while (i < n - 1) {
            // bits[i] == 0, i += 1
            // bits[i] == 1, i += 2
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};
// @lc code=end

