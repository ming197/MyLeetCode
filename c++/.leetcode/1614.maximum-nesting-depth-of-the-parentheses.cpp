/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 * 
 * ref: https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses/solution/gua-hao-de-zui-da-qian-tao-shen-du-by-le-av5b/
 */

// @lc code=start


class Solution {
public:
    int maxDepth(string s) {
        stack<pair<char, int>> stk;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '(') {
                if(stk.empty()){
                    stk.push(make_pair('(', 1));
                }else{
                    stk.push(make_pair('(', stk.top().second + 1));
                }
            }else if(c == ')'){
                res = max(res, stk.top().second);
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end

