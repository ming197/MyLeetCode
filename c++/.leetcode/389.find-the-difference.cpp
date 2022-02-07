/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        char hash_tab[26];
        for(int i = 0; i < 26; i++) hash_tab[i] = 0;
        for(char& c : t) hash_tab[c - 'a']++;
        for(char& c : s) hash_tab[c - 'a']--;
        for(int i = 0; i < 26; i++){
            if(hash_tab[i] == 1) return i + 'a';
        }
        return ' ';
    }
};
// @lc code=end

