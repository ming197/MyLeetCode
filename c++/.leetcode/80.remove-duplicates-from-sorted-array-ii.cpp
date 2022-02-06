/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n)
        {
            /* code */
            nums[i] = nums[j];
            int x = nums[j];
            if(j + 1 < n && nums[j + 1] == x){
                nums[++i] = nums[++j];
            }
            while (j + 1 < n && nums[j+1] == x)
            {
                /* code */
                j++;
            }
            i++;
            j++;
        }
        return i;
    }
};
// @lc code=end

