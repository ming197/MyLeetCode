/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n&1;
        n >>= 1;
        while(n){
            if(bit == (n&1)) return false;
            bit = n&1;
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end

