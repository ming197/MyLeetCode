/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        // split path to "dir" array , store in "stk"
        stack<string> stk;
        path += '/';
        string dir = "";
        for(int i = 0; i < path.size(); i++){
            char c = path[i];
            if(c != '/'){
                dir += c;
            }else{
                if(dir.length() == 0 || dir == ".") {}
                else if(dir == ".."){
                    if(!stk.empty()) stk.pop();
                }else{
                    stk.push(dir);
                }
                dir = "";
            }
        }

        if(stk.size() == 0) return "/";
        string res = "";
        while (!stk.empty())
        {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

