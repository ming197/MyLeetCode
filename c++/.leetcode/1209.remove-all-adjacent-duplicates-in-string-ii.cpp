/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<string> stk;
        int n = s.size();
        int i = 0;
        while (i < n){
            /* code */
            int j = i;
            string curr = "";
            while (j < n && s[j] == s[i])
            {
                /* code */
                if(j - i == k - 1){
                    i = j + 1;
                    curr = "";
                }else curr += s[i];
                j++;
            }
            i = j;
            if(curr != ""){
                if(!stk.empty() && curr[0] == stk.top()[0]){
                    curr += stk.top();
                    stk.pop();
                    if(curr.size() >= k) curr = curr.substr(k);
                }
                if(curr != "") stk.push(curr);
            }
        }
        string res = "";
        while (!stk.empty())
        {
            /* code */
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    string s = "pbbcggttciiippooaais";
    int k = 2;
    Solution sol;
    sol.removeDuplicates(s, k);
    return 0;
}
// @lc code=end

