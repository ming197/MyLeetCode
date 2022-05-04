#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        int i = 0, j = n - 1;
        while (i < j){
            if(nums[i] + nums[j] == k){
                res++;
                i++;j--;
            }else if(nums[i] + nums[j] > k){
                j--;
            }else i++;
        }
        return res;
    }
};