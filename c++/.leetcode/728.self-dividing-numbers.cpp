/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++){
            auto vec = getDigits(i);
            if(isSelfDividingNumber(i, vec)) res.emplace_back(i);
        }
        return res;
    }

    bool isSelfDividingNumber(int x, vector<int>& digits){
        for(int& k : digits){
            if(k == 0 || x % k != 0) return false;
        }
        return true;
    }
    vector<int> getDigits(int x){
        vector<int> res;
        while (x)
        {
            /* code */
            res.emplace_back(x % 10);
            x /= 10;
        }
        return res;
    }
};
// @lc code=end

