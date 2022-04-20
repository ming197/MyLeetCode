/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toGoatLatin(string sentence) {
        int n = sentence.size();
        string s = "";
        int i = 0;
        set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int idx = 0;
        string res;
        while (i < n)
        {
            /* code */
            int j = i;
            while (j < n && sentence[j] != ' ')
            {
                /* code */
                j++;
            }
            string word = sentence.substr(i, j - i);
            i = j;
            while (i < n && sentence[i] == ' '){
                /* code */
                i++;
            }

            idx++;
            string suffix = "";
            for(int k = 0; k < idx; k++) suffix += "a";
            if(set.find(word[0]) != set.end()){
                word += "ma";
            }else{
                word = word.substr(1) + word[0] + "ma";
            }
            word += suffix;
            if(idx > 1) res += " ";
            res += word;
        }
        return res;
    }
};
// @lc code=end

