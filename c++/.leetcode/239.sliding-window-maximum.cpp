/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> d;
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(!d.empty() && d.front() == i - k){
                d.pop_front();
            }

            while (!d.empty() && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }

            d.push_back(i);

            if(i >= k-1){
                res.push_back(nums[d.front()]);
            }
            
        }

        return res;
    }
};
// @lc code=end

