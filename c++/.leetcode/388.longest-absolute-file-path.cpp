/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int i = 0;
        int depth = 0;
        stack<pair<string, int>> stk;
        int len = 0;
        int res = 0;
        while (i < n)
        {
            /* code */
            int j = i;
            while (j < n && input[j] != '\n'){
                /* code */
                j++;
            }
            string s = input.substr(i, j - i);
            
            stk.push(make_pair(s, depth));
            len += s.size() + (depth > 0 ? 1 : 0);
            if(s.find('.') != string::npos){
                res = max(res, len);
            } 
            

            if(j == n){
                i = j;break;
            } 
            
            j++;
            int cnt = 0;
            while (j < n && input[j] == '\t'){
                /* code */
                cnt++;
                j++;
            }

            while (!stk.empty() && stk.top().second >= cnt)
            {
                /* code */
                len -= stk.top().first.size() + (stk.top().second > 0 ? 1 : 0);
                stk.pop();
            }
            depth = stk.empty() ? 0 : stk.top().second + 1;
            i = j;
            
        }
        return res;
    }
};

int main(){
    Solution solution;
    string s = "dir\n\t        file.txt\n\tfile2.txt";
    cout << solution.lengthLongestPath(s)<< endl;
    return 0;
}
// @lc code=end

