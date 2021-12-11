/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n+1, 1);
        if(s[0] == '0') return 0;
        for(int i = 2; i <= n; i++){
            if(s[i-1] == '0'){
                if(s[i-2] == '0' || s[i-2] > '2') return 0;
                f[i] = f[i-2];
            }else if('0' < s[i-1] && s[i-1] < '7'){ // 1 - 6
                if(s[i-2] == '1' || s[i-2] == '2'){
                    f[i] = f[i-1] + f[i-2];
                }else{
                    f[i] = f[i-1];
                }
            }else{ // 7 - 9
                if(s[i-2] == '1'){
                    f[i] = f[i-1] + f[i-2];
                }else f[i] = f[i-1];
            } 
        }
        return f[n];
    }
};

// int  main(){
//     Solution solution;
//     solution.numDecodings("12");
//     return 0;
// }
// @lc code=end

