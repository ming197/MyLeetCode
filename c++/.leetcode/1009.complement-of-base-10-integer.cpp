/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        int base = 1;
        while (base < n)
        {
            /* code */
            base <<= 1;
            base++;
        }
        return base - n;
    }
};
// @lc code=end

