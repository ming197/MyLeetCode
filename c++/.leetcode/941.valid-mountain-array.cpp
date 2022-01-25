/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int max = arr[0];
        int max_id = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
                max_id = i;
            }
        }
        if(max_id == 0 || max_id == n - 1) return false;
        // left
        int r = max;
        for(int i = max_id - 1; i >= 0; i--){
            if(arr[i] < r){
                r = arr[i];
            }else return false;
        }
        int l = max;
        for(int i = max_id + 1; i < n; i++){
            if(arr[i] < l){
                l = arr[i];
            }else return false;
        }
        return true;
    }
};
// @lc code=end

