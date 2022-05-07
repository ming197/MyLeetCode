/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size(), k = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < k) return true;
            while(!st.empty() and st.top() < nums[i]) { 
                k = max(k,st.top()); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end

