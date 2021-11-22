/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) i++;
        }
        if (i == n)
            return s;
        }
        string remain_rev = s.substr(i, n);
        

};
// @lc code=end

