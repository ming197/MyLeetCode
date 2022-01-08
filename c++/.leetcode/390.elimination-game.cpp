/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remain = n;
        int step = 1;
        int head = 1;
        while (remain > 1)
        {
            /* code */
            if(left || (remain&1) == 1){
                head += step;
            }
            step *= 2;
            remain >>= 1;
            left = !left;
        }
        return head;
    }
};
// @lc code=end

