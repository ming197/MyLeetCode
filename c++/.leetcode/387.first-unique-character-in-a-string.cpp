/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int ch[26] = {0};
        for(char c : s) ch[c - 'a']++;
        int i = 0;
        for(char c : s){
            if(ch[c - 'a'] == 1) return i;
            i++;
        }
        return -1;
    }
};
// @lc code=end

