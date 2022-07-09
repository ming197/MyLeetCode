/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> val2Indice;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            val2Indice[arr[i]] = i;
        }   
        vector<vector<int>> f(n, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--){
                int k = -1;
                if(val2Indice.count(arr[i] - arr[j])){
                    k = val2Indice[arr[i] - arr[j]];
                }
                if(k >= 0){
                    f[j][i] = max(f[k][j] + 1, 3);
                }
                ans = max(ans, f[j][i]);
            }
        }
        return ans;
    }
};
// @lc code=end

