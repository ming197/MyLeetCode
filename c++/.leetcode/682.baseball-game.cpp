/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for(auto& c : ops){
            if("C" == c){
                scores.pop_back();
            }else if (c == "D")
            {
                /* code */
                scores.emplace_back(scores.back() * 2);
            }else if(c == "+"){
                scores.emplace_back(scores.back() + scores[scores.size() - 2]);
            }else{
                scores.emplace_back(stoi(c));
            }            
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
// @lc code=end

