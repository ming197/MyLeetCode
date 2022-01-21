/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            /* code */
            if(s[i] != s[j]) break;
            i++;
            j--;
        }
        if(i == j) return 1;
        return 2;
    }
};
// @lc code=end

