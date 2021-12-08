/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()) return nums;
        unordered_map<int, int> hash_table;
        for(int x : nums){
            hash_table[x]++;
        }

        // min_heap
        auto cmp = [&hash_table](int x, int y){
            return hash_table[x] > hash_table[y];
        };

        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

        for(pair<int, int> p : hash_table){
            heap.push(p.first);
            if(heap.size() > k) heap.pop();
        }

        vector<int> top(k);
        for(int i = 0; i < k; i++){
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};
// @lc code=end

