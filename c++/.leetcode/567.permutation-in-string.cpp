/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> hash_table(26, 0);
        for(int i = 0; i < n; i++){
            hash_table[s1[i] - 'a']++;
        }
        vector<int> temp_tale(26, 0);
        int l = 0, r = -1;
        while (++r < m)
        {
            temp_tale[s2[r] - 'a']++;
            // compare the lastest character is enough
            while (l <= r && temp_tale[s2[r] - 'a'] > hash_table[s2[r] - 'a'])
            {
                temp_tale[s2[l] - 'a']--;
                l++;
            }
            if(r - l + 1 == n) return true;
        }
        return false;
    }
};
// @lc code=end

