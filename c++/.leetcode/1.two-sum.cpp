/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        for(int i = 0; i < nums.size(); i++){
            auto it = hash_table.find(target - nums[i]);
            if(it != hash_table.end()){
                return {it->second, i};
            }
            hash_table[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

