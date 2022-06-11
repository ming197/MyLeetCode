/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sum -= x;
        int n = nums.size();
        // find max-length subarray, sum of which equals "sum"
        vector<int> preSum(n + 1, 0);
        // preSum[0] = nums[0];
        for(int i = 0; i < n; i++){
            preSum[i + 1] = preSum[i] + nums[i];
        }

        int res = -1;
        for(int end = n; end >= 0; end--){
            int l = 0, r = end;
            while (l < r)
            {
                /* code */
                int mid = l + (r - l + 1 >> 1);
                if(preSum[end] - preSum[mid] < sum){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }

            if(preSum[end] - preSum[l] == sum){
                res = max(res, end - l);
            }
            
        }

        return res == -1 ? -1 : n - res;
    }
};
// @lc code=end

