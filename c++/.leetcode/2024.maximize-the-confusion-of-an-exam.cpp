/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        return max(getCnt(answerKey, n, k, 'T'), getCnt(answerKey, n, k, 'F'));
    }

    int getCnt(string& s, int n, int k, char c){
        int ans = 0;
        for(int i = 0, j = 0, cnt = 0; i < n; i++){
            if(s[i] == c) cnt++;
            while (cnt > k)
            {
                /* code */
                if(s[j] == c) cnt--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
// @lc code=end

