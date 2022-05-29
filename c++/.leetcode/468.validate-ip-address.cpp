/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string res[3] = {"IPv4", "IPv6", "Neither"};
    string validIPAddress(string queryIP) {
        // int res_idx = 0;
        int i = 0, j = 0;
        int n = queryIP.size();
        int flag = -1;
        int cnt = 0;
        while (i < n)
        {
            /* code */
            j = i;
            string s = "";
            while (j < n && queryIP[j] != '.' && queryIP[j] != ':'){
                /* code */
                j++;
            }
            if(j < n){
                if(flag == -1){
                    flag = queryIP[j] == '.' ? 0 : 1;
                }else{
                    if((queryIP[j] == '.' ? 0 : 1) != flag) return res[2];
                }
            }
            s = queryIP.substr(i, j - i);
            i = j + 1;
            if(i == n) return res[2];
            cnt++;

            if(!flag){ // ipv4
                if(s.size() < 1 || s.size() > 3) return res[2];
                for(char& c : s){
                    if(c < '0' || c > '9') return res[2];
                }
                
                int x = stoi(s);
                if(x < 0 || x > 255) return res[2];
                // 前导零
                if(s != to_string(x)) return res[2];
            }else{ // ipv6
                if(s.size() < 1 || s.size() > 4) return res[2];
                for(auto& c : s){
                    if('0' <= c && c <= '9') continue;
                    if('a' <= c && c <= 'f') continue;
                    if('A' <= c && c <= 'F') continue;
                    return res[2];
                }
            }
        }
        if(!flag){
            if(cnt != 4) return res[2];
        }else{
            if(cnt != 8) return res[2];
        }
        return res[flag];
    }
};

int main(){
    Solution solution;
    string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    solution.validIPAddress(queryIP);
    return 0;
}
// @lc code=end

