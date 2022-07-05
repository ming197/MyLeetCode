/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for (int i = 0; i < expression.size();) {
            if (!isdigit(expression[i])) {
                if (expression[i] == '+') {
                    ops.push_back(ADDITION);
                } else if (expression[i] == '-') {
                    ops.push_back(SUBTRACTION);
                } else {
                    ops.push_back(MULTIPLICATION);
                }
                i++;
            } else {
                int t = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    t = t * 10 + expression[i] - '0';
                    i++;
                }
                ops.push_back(t);
            }
        }

        vector<vector<vector<int>>> dp((int) ops.size(), vector<vector<int>>((int) ops.size()));
        for (int i = 0; i < ops.size(); i += 2) {
            dp[i][i] = {ops[i]};
        }
        for (int i = 3; i <= ops.size(); i++) {
            for (int j = 0; j + i <= ops.size(); j += 2) {
                int l = j;
                int r = j + i - 1;
                for (int k = j + 1; k < r; k += 2) {
                    auto& left = dp[l][k - 1];
                    auto& right = dp[k + 1][r];
                    for (auto& num1 : left) {
                        for (auto& num2 : right) {
                            if (ops[k] == ADDITION) {
                                dp[l][r].push_back(num1 + num2);
                            }
                            else if (ops[k] == SUBTRACTION) {
                                dp[l][r].push_back(num1 - num2);
                            }
                            else if (ops[k] == MULTIPLICATION) {
                                dp[l][r].push_back(num1 * num2);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][(int) ops.size() - 1];
    }
};
// @lc code=end

