/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> f(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 0; i < n; i++){
            left[i] = nums[i] + (i == 0 ? 0 : left[i-1]);
        }
        for(int i = n - 1; i > -1; i--){
            right[i] = nums[i] + (i == n - 1 ? 0 : right[i + 1]);
        }
        for(int i = 0; i < n; i++){
            f[0] += i * nums[i];
        } 
        for(int i = 1; i < n; i++){
            f[i] = f[i - 1] - right[i];
            f[i] += nums[i - 1] * (n - 1);
            f[i] -= i == 1 ? 0 : left[i - 2];
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end

