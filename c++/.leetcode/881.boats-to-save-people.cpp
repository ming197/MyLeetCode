/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int res = 0;
        while (l <= r)
        {
            /* code */
            if(people[l] + people[r] <= limit){
                l++;
            }
            r--;
            res++;
        }
        return res;
    }
};
// @lc code=end

