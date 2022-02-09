/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> cnt;
        for(int& x : nums){
            cnt[x]++;
        }
        auto it = cnt.begin();
        for(it; it != cnt.end(); it++){
            if(k == 0){
                if(it->second >= 2) res++;
            }else{
                if(cnt.find(it->first + k) != cnt.end()){
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

