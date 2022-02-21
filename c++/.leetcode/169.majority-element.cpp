/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int times = 1, majorEle = nums[0];
        for(int i = 1; i < (int) nums.size(); i++){
            if(times == 0){
                majorEle = nums[i];
                times = 1;
                continue;
            }
            if(nums[i] == majorEle) times++;
            else times--;
        }
        return majorEle;
    }
};
// @lc code=end

