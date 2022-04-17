/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        int i = 0;
        while (i < paragraph.size())
        {
            /* code */
            int j = i;
            while (j < paragraph.size() && ('a' <= paragraph[j] && paragraph[j] <= 'z') || ('A' <= paragraph[j] && paragraph[j] <= 'Z'))
            {
                /* code */
                j++;
            }
            string word = paragraph.substr(i, j - i);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(!word.empty()) map[word]++;
            i = j;i++;
        }
        for(auto& word : banned){
            map.erase(word);
        }
        int freq = 0;
        string res = "";
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second > freq){
                res = it->first;
                freq = it->second;
            } 
        }
        return res;
    }
};
// @lc code=end

