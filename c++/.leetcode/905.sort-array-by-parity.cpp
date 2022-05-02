/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        for(int k = 0; k < nums.size(); k++){
            if((nums[k] & 1) == 0){
                swap(nums, i++, k);
            }
        }
        return nums;
    }

    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
// @lc code=end

