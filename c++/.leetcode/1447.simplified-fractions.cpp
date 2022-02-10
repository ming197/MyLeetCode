/*
 * @lc app=leetcode id=1447 lang=cpp
 *
 * [1447] Simplified Fractions
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        set<string> res;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i == 9 && j == 6) {
                    int k = 3;
                }
                int comDiv = commonDivisor(j, i);
                res.insert(to_string(j / comDiv) + "/" + to_string(i / comDiv));
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    int commonDivisor(int x, int y){
        return y == 0 ? x : commonDivisor(y, x % y);
        // vector<int> fac;
        // for(int f = 1; f <= x; f++){
        //     if(x % f == 0) {
        //         fac.emplace_back(f);
        //     }
        // }
        // fac.emplace_back(x);
        // for(int i = fac.size() - 1; i > -1; i--){
        //     if(y % fac[i] == 0) return fac[i];
        // }
        // return 1;
    }
};
// @lc code=end

