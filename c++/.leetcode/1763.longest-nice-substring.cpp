/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int maxPos = 0;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            int lower = 0;
            int upper = 0;
            for(int j = i; j < n; j++){
                if (islower(s[j])){
                    lower |= 1 << (s[j] - 'a');
                }
                else{
                    upper |= 1 << (s[j] - 'a');
                }
                if(lower == upper && j - i + 1 > maxLen){
                    maxPos = i;
                    maxLen = j - i + 1;
                } 
            }
        }
        return s.substr(maxPos, maxLen);
    }
};
// @lc code=end

