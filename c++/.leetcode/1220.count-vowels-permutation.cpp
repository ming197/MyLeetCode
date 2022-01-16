/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        int mod = 1e9 + 7;
        int count[5] = {1, 1, 1, 1, 1};
        int k = 1;
        while(k < n){
            int next[5];
            next[0] = ((count[1] + count[2]) % mod + count[4]) % mod;
            next[1] = (count[0] + count[2]) % mod;
            next[2] = (count[1] + count[3]) % mod;
            next[3] = count[2];
            next[4] = (count[2] + count[3]) % mod;
            for(int i = 0; i < 5; i++) count[i] = next[i];
            k++;
        }
        int res = 0;
        for(int& x : count){
            res = (res + x) % mod;
        }
        return res;
    }
};
// @lc code=end

