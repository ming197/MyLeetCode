/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> hash_tab(26, 0);
        for(char& c : text){
            hash_tab[c - 'a']++;
        }
        int res = 1e4;
        string balloon = "balloon";
        hash_tab['l' - 'a'] /= 2;
        hash_tab['o' - 'a'] /= 2;
        for(char& c : balloon){
            res = min(res, hash_tab[c - 'a']);
        }
        return res;
    }
};
// @lc code=end

