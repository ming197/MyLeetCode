/*
 * @lc app=leetcode id=1414 lang=cpp
 *
 * [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        vector<int> f;
        f.emplace_back(1);
        while (b <= k)
        {
            /* code */
            f.emplace_back(b);
            int c = a + b;
            a = b;
            b = c;
        }
        int ans = 0;
        for(int i = f.size() - 1; i >= 0 && k > 0; i--){
            int num = f[i];
            if(k >= num){
                k -= num;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

