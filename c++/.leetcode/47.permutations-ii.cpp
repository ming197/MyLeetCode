#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> visited;
    int n;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        visited = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums){
        if(tmp.size() == n){
            res.emplace_back(tmp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]){
                    continue;
                }
                tmp.emplace_back(nums[i]);
                visited[i] = true;
                backtrack(nums);
                visited[i] = false;
                tmp.pop_back();
            }
        }
    }
};