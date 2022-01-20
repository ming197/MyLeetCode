/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_table;
        for(int i = 0; i < nums.size(); i++){
            auto it = hash_table.find(nums[i]);
            if(it != hash_table.end()){
                if(abs(it->second - i) <= k) return true;
            }
            hash_table[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

