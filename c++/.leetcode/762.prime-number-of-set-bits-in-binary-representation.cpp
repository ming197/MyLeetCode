/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, bool> map; 
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++){
            int num = i;
            int x = 0;
            while (num)
            {
                /* code */
                x += (num&1);
                num >>= 1;
            }
            if(map.find(x) == map.end()) {
                map[x] = isPrime(x);
            }
            if(map[x]) res++;
        }
        return res;
    }

    bool isPrime(int x){
        if(x == 1) return false;
        int up_bound = sqrt(x);
        for(int i = 2; i <= up_bound; i++){
            if(x % i == 0) return false;
        }
        return true;
    }
};
// @lc code=end

