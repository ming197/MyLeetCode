#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int res = 0;
        for(auto& fruit : fruits){
            int type = fruit[0], num = fruit[1];
            int times = (num - 1) / limit + 1;
            res += (times * time[type]);
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> time{2, 3, 2};
    vector<vector<int>> fruits{{0, 2}, {1, 4}, {2, 1}};
    int limit = 3;
    solution.getMinimumTime(time, fruits, limit);
    return 0;
}