/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        
        for(auto& c : s){
            if(c == '#'){
                if(!stk1.empty()) stk1.pop();
            }else stk1.push(c);
        }
        
        for(auto& c : t){
            if(c == '#'){
                if(!stk2.empty()) stk2.pop();
            }else stk2.push(c);
        }
        
        if(stk1.size() != stk2.size()) return false;
        
        while(!stk1.empty()){
            if(stk1.top() != stk2.top()) return false;
            stk1.pop();stk2.pop();
        }
        return true;
    }
};
// @lc code=end

