/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int res = num;
        while (res > 9)
        {
            /* code */
            vector<int> digits;
            while (num > 0)
            {
                /* code */
                digits.emplace_back(num % 10);
                num /= 10;
            }
            res = accumulate(digits.begin(), digits.end(), 0);
            num = res;
        }
        return res;
    }
};
// @lc code=end

