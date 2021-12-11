/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start

/**
 * @brief solution: https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
 * 
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash_table(26, 0);
        for(char task : tasks){
            hash_table[task - 'A']++;
        }
        int k = 0;
        for(int i = 0; i < 26; i++){
            k = max(k, hash_table[i]);
        }
        int res = (k - 1) * (n + 1);
        for(int i = 0; i < 26; i++){
            if(hash_table[i] == k) res++;
        }
        return max(res, (int) tasks.size());
    }
};
// @lc code=end

