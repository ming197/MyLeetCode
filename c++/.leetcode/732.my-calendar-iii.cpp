/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyCalendarThree {
private:
    unordered_map<int, int> tree;
    unordered_map<int, int> lazy;
public:
    MyCalendarThree() {

    }

    void update(int start, int end, int l, int r, int node)
    {
        if(start > r || end < l) {
            return;
        } else if(start <= l && r <= end) { 
            // 当前区间被检索区间覆盖, 因此区间内所有元素都加一
            // 自然而然，无论当前节点区间的最大值为多少，当该区间的所有
            // 元素值都加一时，其拥有的最大值自然也需要加一位
            ++tree[node]; 
            ++lazy[node];
        } else {
            int left_node = node*2, right_node = node*2 + 1;
            int mid = (l+r) >> 1;
            update(start, end, l, mid, left_node);
            update(start, end, mid+1, r, right_node);
            tree[node] = lazy[node] + max(tree[left_node], tree[right_node]);
        }
    }
    
    int book(int start, int end) {
        update(start, end-1, 0, 1e9, 1);
        return tree[1];
    }
};


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

