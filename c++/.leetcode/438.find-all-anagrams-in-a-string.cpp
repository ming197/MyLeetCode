/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m = s.size(), n = p.size();
        if(n > m) return res;
        vector<int> p_tab(26, 0);
        for(char& c : p){
            p_tab[c - 'a']++;
        }
        vector<int> tab(26, 0);
        int l = 0, r = 0;
        while(r < m){
            while (r < m && r - l + 1 <= n)
            {
                /* code */
                tab[s[r]-'a']++;
                r++;
            }
            if(equal(p_tab, tab)){
                res.emplace_back(l);
            }
            tab[s[l] - 'a']--;
            l++;
        }
        return res;
    }
    bool equal(vector<int>& a, vector<int>& b){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};
// @lc code=end

