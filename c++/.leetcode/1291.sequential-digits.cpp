/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i =1 ; i <= 8; i++){
            int num = i;
            for(int j = i + 1; j <= 9; j++){
                num = num *  10 + j;
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

