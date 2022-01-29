/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        
        auto insert = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                ++freq[move(word)];
            }
        };

        insert(s1);
        insert(s2);

        vector<string> ans;
        for (const auto& [word, occ]: freq) {
            if (occ == 1) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};
// @lc code=end

