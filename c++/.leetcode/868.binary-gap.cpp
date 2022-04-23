/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int l = -1, r = -1;
        int i = 0;
        int res = 0;
        while (n)
        {
            /* code */
            int bit = n&1;
            n >>= 1;
            if(bit){
                if(l == -1){
                    l = i;
                }else{
                    res = max(res, i - l);
                    l = i;
                }
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

