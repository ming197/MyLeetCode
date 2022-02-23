/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string reverse_ = "";
        string noneChar = "";
        for(char& c : s){
            if(!isChar(c)) noneChar += c;
            else reverse_ += c;
        }
        reverse(reverse_.begin(), reverse_.end());
        string res = "";
        int i = 0, j = 0;
        for(char& c : s){
            if(!isChar(c)){
                res += noneChar[j++];
            }else{
                res += reverse_[i++];
            }
        }
        return res;
    }

    bool isChar(char c){
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
};
// @lc code=end

