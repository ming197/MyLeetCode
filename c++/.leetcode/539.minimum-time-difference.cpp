/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int mod = 24 * 60;
        vector<bool> hash_tab(mod, false);
        int min_t = mod, max_t = -1;
        for(auto& t : timePoints){
            int x = strToInt(t);
            min_t = min(min_t, x);
            max_t = max(max_t, x);
            if(hash_tab[x]) return 0;
            hash_tab[x] = true;
        }

        int res = (min_t + mod) - max_t;
        int i = min_t;
        int j = i + 1;
        while (j <= max_t)
        {
            /* code */
            if(hash_tab[j] == true){
                res = min(res, j - i);
            }
            j++;
        }
        return res;
    }

    int strToInt(string str){
        int h = (str[0] - '0') * 10 + str[1] - '0';
        int m = (str[3] - '0') * 10 + str[4] - '0';

        return h*60 + m;
    }
};
// @lc code=end

