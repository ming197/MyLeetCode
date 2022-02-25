/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        vector<int> a = getNum(num1);
        vector<int> b = getNum(num2);
        int x = a[0] * b[0] - a[1] * b[1];
        int y = a[0] * b[1] + a[1] * b[0];
        return to_string(x) + "+" + to_string(y) + "i";
    }

    vector<int> getNum(string num1){
        string x, y;
        bool flag = false;
        int idx = 0;
        while (idx < num1.size())
        {
            /* code */
            if(num1[idx] == 'i') break;
            if(num1[idx] == '+'){
                flag = true;
            }else{
                if(flag){
                    y += num1[idx];
                }else{
                    x += num1[idx];
                }
            }
            idx++;
        }
        return {stoi(x), stoi(y)};
    }
};
// @lc code=end

