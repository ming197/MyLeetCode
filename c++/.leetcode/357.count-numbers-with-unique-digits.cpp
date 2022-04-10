/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> f(n+1);
        f[0] = 1;
        f[1] = 9;
        for(int i = 2; i <= n; i++){
            // int x = pow(10, i) - pow(10, i - 1);
            int next_digit = 10 - (i-1);
            f[i] = f[i-1] * next_digit;
        }
        int res = 0;
        for(int i = 0; i <= n; i++){
            res += f[i];
        }
        return res;
    }
};
// @lc code=end

