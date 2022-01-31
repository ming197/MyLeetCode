/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        int res = 0;
        while (num > 1)
        {
            /* code */

            if((num&1) == 1) res += 2;
            else res++;
            num >>= 1;
        }
        return ++res;
    }
};
// @lc code=end

