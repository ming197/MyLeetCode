/*
 * @lc app=leetcode id=2047 lang=cpp
 *
 * [2047] Number of Valid Words in a Sentence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidWords(string sentence) {
        vector<string> strs;
        int n = sentence.size();
        int l = 0, r = 0;
        int res = 0;
        while(r < sentence.size()){
            if(sentence[r] == ' '){
                if(r > l){
                    string s = sentence.substr(l, r - l);
                    res += validWord(s) ? 1 : 0;

                }
                while (r < n && sentence[r] == ' ')
                {
                    /* code */
                    r++;
                }
                l = r;
            }else r++;
        }
        if(r > l){
            string s = sentence.substr(l, r - l);
            res += validWord(s) ? 1 : 0;
        }
        return res;
    }

    bool validWord(string& s){
        int n = s.size();
        bool flag = true;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if('0' <= c && c <= '9') return false;
            if('a' <= c && c <= 'z'){}
            else if(c == '-'){
                if(!flag) return false;
                if(i == 0 || i == n - 1 || !islower(s[i - 1]) || !islower(s[i + 1])) return false;
                flag = false;
            }else{
                if(i != n - 1) return false;
            }
        }
        return true;
    }
};
// @lc code=end

