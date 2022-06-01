/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;
        int l = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        vector<int> edges(4);        
        return backtrack(0, matchsticks, edges, l);
    }

    bool backtrack(int index, vector<int>& matchsticks, vector<int>& edges, int len){
        if(index == matchsticks.size()) {
            return true;
        }

        for(int i = 0; i < edges.size(); i++){
            edges[i] += matchsticks[index];
            if(edges[i] <= len && backtrack(index + 1, matchsticks, edges, len)){
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};
// @lc code=end

