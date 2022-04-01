/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) {
            ++cnt[x];
        }
        if (cnt[0] % 2) {
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt) {
            vals.push_back(x);
        }
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) { // 无法找到足够的 2x 与 x 配对
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};
// @lc code=end

