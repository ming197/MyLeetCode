/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });
        auto cmp = [&](int a, int b){
            return trips[a][2] > trips[b][2];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        int i = 0;
        int passengerCount = 0;
        while (i < n)
        {
            /* code */
            while (!q.empty() && trips[i][1] >= trips[q.top()][2])
            {
                /* code */
                passengerCount -= trips[q.top()][0];
                q.pop();
            }
            passengerCount += trips[i][0];
            if(passengerCount > capacity) return false;
            q.push(i++);
        }
        return true;
    }
};
// @lc code=end

