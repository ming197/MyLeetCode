/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 * ref: https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (char& c : instructions){
            if (c == 'R'){
                i = (i + 1) % 4;
            }else if(c == 'L'){
                i = (i + 3) % 4;    
            }else{
                x += dx[i], y += dy[i];
            }    
        }   
        return (x == 0 && y == 0) || i > 0;
    }
};
// @lc code=end

