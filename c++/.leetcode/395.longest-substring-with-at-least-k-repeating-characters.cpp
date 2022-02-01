/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }
    int dfs(const string& s, int l, int r, int k){
        vector<int> cnt(26, 0);
        for(int i = l; i <= r; i++){
            cnt[s[i] - 'a']++;
        }

        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }

        if(split == 0) return r - l + 1;

        int i = l;
        int res = 0;
        while (i <= r)
        {
            /* code */
            while (i <= r && s[i] == split) {
                i++;
            }
            if (i > r) {
                break;
            }

            int start = i;
            while (i <= r && s[i] != split)
            {
                /* code */
                i++;
            }
            
            int len = dfs(s, start, i - 1, k);
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end

