/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(string& s : emails){
            int i = 0, j = -1;
            int n = s.size();
            string local_name;
            string domain_name;
            bool flag = false;

            while (++j < n ){
                /* code */
                if(s[j] == '@'){
                    domain_name = s.substr(j, n - j);
                    break;
                }

                if(s[j] == '+'){
                    flag = true;
                }

                if(flag) continue;

                if(s[j] == '.') continue;

                if('a' <= s[j] && s[j] <= 'z'){
                    local_name += s[j];
                }
            }
            set.insert(local_name + domain_name);
        }

        return set.size();
    }
};
// @lc code=end

