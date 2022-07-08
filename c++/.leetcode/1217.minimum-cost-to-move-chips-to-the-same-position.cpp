/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        int n = position.size();
        for(int i = 0; i < n; i++){
            if((position[i]&1) == 0){
                even++;
            }else odd++;
        }

        return min(odd, even);
    }
};
// @lc code=end

