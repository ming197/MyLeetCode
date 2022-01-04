/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return kmp((s+s).substr(1, s.size()*2 - 2), s);
    }

    bool kmp(const string& query, const string& pattern){
        int n = query.size();
        int m = pattern.size();

        vector<int> f(m, -1);

        for(int i = 1; i < m; i++){
            int t = f[i - 1];
            while (t != -1 && pattern[t + 1] != pattern[i])
            {
                /* code */
                t = f[t];
            }
            if(pattern[t + 1] == pattern[i]) f[i] = t + 1;
        }

        int t = -1;
        for(int i = 0; i < n; i++){
            while (t != -1 && query[i] != pattern[t+1])
            {
                /* code */
                t = f[t];
            }

            if(query[i] == pattern[t+1]) t++;

            if(t == m-1) return true;
        }

        return false;
    }
};
// @lc code=end

