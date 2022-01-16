/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> person;
        int res = 1;
        int i = 0;
        while(seats[i] != 1){
            i++;
        }
        res = i;
        person.emplace_back(i);
        int j = n - 1;
        while(seats[j] != 1){
            j--;
        }
        res = max(res, (int)(n - 1 - j));
        for(int k = i + 1; k <= j; k++){
            if(seats[k] == 1){
                int l = k - person.back();
                res = max(res, l / 2);
                person.emplace_back(k);
            }
        }
        return res;
    }
};
// @lc code=end

