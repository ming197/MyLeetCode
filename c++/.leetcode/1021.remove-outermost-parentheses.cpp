/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int i = 0, j = -1;
        int n = s.size();
        int left = 0, right = 0;
        while(i < n){
            j = i + 1;
            left = 1;
            while(j < n && left > right){
                if(s[j] == '(') left++;
                else right++;
                j++;
            }
            res += s.substr(i + 1, j - i - 2);
            right = 0;
            i = j;
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s = "()()";
    sol.removeOuterParentheses(s);
    return 0;
}
// @lc code=end

