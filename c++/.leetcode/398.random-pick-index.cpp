/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<int>> hash_table;
    Solution(vector<int>& nums) {
        int i = 0;
        for(int& x : nums){
            if(hash_table.find(x) == hash_table.end()){
                hash_table[x] = {i};
            }else{
                hash_table[x].push_back(i);
            }
            i++;
        }
    }
    
    int pick(int target) {
        int n = hash_table[target].size();
        int idx = rand() % n;
        return hash_table[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

