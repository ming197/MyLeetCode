/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nums;
    int n;
    int singleNonDuplicate(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        int l = 0, r = n-1;
        if(isSingle(l)) return nums[l];
        if(isSingle(r)) return nums[r];
        while(l < r){
            int mid = l + (r - l >> 1);
            if(isSingle(mid)) return nums[mid];
            else{
                int rightLen;
                if(nums[mid + 1] == nums[mid]){
                    mid++;
                }
                rightLen = r - mid;
                if((rightLen&1) == 1) l = mid + 1;
                else r = mid - 2;
            }
        }
        return nums[l];
    }

    bool isSingle(int x){
        if(x - 1 > -1 && nums[x - 1] == nums[x]) return false;
        if(x + 1 < n && nums[x + 1] == nums[x]) return false;
        return true;
    }
};
// @lc code=end

