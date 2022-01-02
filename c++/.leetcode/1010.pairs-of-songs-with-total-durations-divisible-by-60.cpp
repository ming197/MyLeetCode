/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hash_table(60, 0);
        int res = 0;
        for(int& x : time){
            int a = x % 60;
            if(a == 0){
                res += hash_table[a];
            }else{
                res += hash_table[60 - a];
            }
            hash_table[a]++;
        }
        return res;
    }
};
// @lc code=end

