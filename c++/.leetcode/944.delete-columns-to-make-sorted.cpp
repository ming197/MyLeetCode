#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int res = 0;
        for(int j = 0; j < n; j++){
            bool flag = false;
            for(int i = 0; i < m - 1 && !flag; i++){
                if(strs[i][j] - strs[i + 1][j] > 0) {
                    flag = true;
                }
            }
            res += flag ? 1 : 0;
        }
        return res;
    }
};