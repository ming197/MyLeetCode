/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
class Solution {
public:
    vector<string> nums;
    bool flag = false;
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n < 3) return false;
        dfs(num, n, 0);
        return flag;
    }

    void dfs(string& num, int& n, int start){
        if(flag) return;
        if(nums.size() < 2){
            if(nums.size() == 0){
                for(int l = 1; l <= (n - 1) / 2; l++){
                    if(l > 1 && num.substr(start, l)[0] == '0') continue;
                    nums.emplace_back(num.substr(start, l));
                    dfs(num, n, start + l);
                    if(flag) return;
                    nums.pop_back();
                }
            }else{
                int l0 = nums[0].size();
                for(int l = 1; max(l, l0) <= n - l - nums[0].size(); l++){
                    if(l > 1 && num.substr(start, l)[0] == '0') continue;
                    nums.emplace_back(num.substr(start, l));
                    dfs(num, n, start + l);
                    if(flag) return;
                    nums.pop_back();
                }
            }
        }else{ // size == 3
            string a = nums[0], b = nums[1];
            string c = add(a, b);
            while (start + c.size() - 1 < n)
            {
                /* code */
                if(c.compare(num.substr(start, c.size())) == 0){
                    start += c.size();
                    if(start == n) {
                        flag = true;
                        return;
                    }
                    a = b;
                    b = c;
                    c = add(a, b);
                }else return;
            }
        }
    }

    // a <= c && b <= c
    string add(string a, string b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c = "";
        int i = 0, j = 0;
        int carry = 0;
        while (i < a.size() || j < b.size() || carry != 0)
        {
            /* code */
            int x = 0, y = 0;
            if(i < a.size()){
                x = a[i] - '0';
                i++;
            }
            if(j < b.size()){
                y = b[j] - '0';
                j++;
            }
            int sum = x + y + carry;
            carry = sum / 10;
            c += (sum % 10) + '0';
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
// @lc code=end

