/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        unordered_map<char, int> ch2index;
        ch2index[c] = -(1e4 + 10);
        int n = s.size();
        vector<int> res(n, 1e4 + 10);

        for(int i = 0; i < n; i++){
            ch2index[s[i]] = i;
            res[i] = min(res[i], abs(i - ch2index[c]));
        }

        for(int i = n - 1; i >= 0; i--){
            ch2index[s[i]] = i;
            res[i] = min(res[i], abs(i - ch2index[c]));
        }
        return res;
    }
};
// @lc code=end

