/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n)
        {
            /* code */
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n)
            {
                /* code */
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if(sumOfCost > sumOfGas) break;
                cnt++;
            }
            if(cnt == n){
                return i;
            }else i = i + cnt + 1;
        }
        return -1;
    }
};
// @lc code=end

