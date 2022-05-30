/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return  INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long a = abs(dividend), b = abs(divisor);

        int res = 0;
        while (a >= b)
        {
            /* code */
            long factor = b, coff = 1;
            while (a - factor >= factor)
            {
                /* code */
                factor <<= 1;
                coff <<= 1;
            }
            res += coff;
            a -= factor;
        }
        
        return (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -res : res;
    }
};
// @lc code=end

