/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        if(word[0] >= 'a' && word[0] <= 'z'){
            for(char& letter : word){
                if(!(letter >= 'a' && letter <= 'z')) return false;
            }
        }else{
            word = word.substr(1);
            if(word[0] >= 'a' && word[0] <= 'z'){
                for(char& letter : word){
                    if(!(letter >= 'a' && letter <= 'z')) return false;
                }
            }else{
                for(char& letter : word){
                    if(!(letter >= 'A' && letter <= 'Z')) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

