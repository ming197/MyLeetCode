/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0, j = 0;
        int carry = 0;
        while (i < num1.size() || j < num2.size())
        {
            /* code */
            int x = 0, y = 0;
            if(i < num1.size()){
                x = num1[i++] - '0';
            }
            if(j < num2.size()){
                y = num2[j++] - '0';
            }

            int sum = x + y + carry;

            res += (sum % 10 + '0');
            carry = sum / 10;
        }
        if(carry != 0) res += (carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

