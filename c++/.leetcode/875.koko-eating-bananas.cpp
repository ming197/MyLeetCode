/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 20;
        while (l < r)
        {
            /* code */
            int m = l + ((r - l) >> 1);
            int total = 0;
            for(int& p : piles){
                total += (p + m - 1) / m;
            }
            if(total > h) l = m + 1;
            else r = m;
        }
        return l;
    }
};
// @lc code=end

