/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        
        while(i < j) {
            if(s[i] != s[j])
                return (check(s, i+1, j) || check(s, i, j-1));
            else {
                i++;
                j--;
            }
        }
        return true;
    }
public:
    bool check(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

