/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0; 
        int j = 0;
        int n1 = version1.size(); 
        int n2 = version2.size();
        
        int num1 = 0;
        int num2 = 0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0');
                i++;
            }
            
            while(j<n2 && version2[j]!='.'){
                num2 = num2*10+(version2[j]-'0');;
                j++;
            }
            
            if(num1>num2) return 1;
            else if(num1 < num2) return -1;
            
            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }
        
        return 0;
    }
};
// @lc code=end
