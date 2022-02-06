/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> hash_tab(110, 0);
        for(int& x : nums){
            hash_tab[x]++;
        }
        int res = 0;
        for(int i = 0; i < 110; i++){
            if(hash_tab[i] == 1) res += i;
        }
        return res;
    }
};
// @lc code=end

