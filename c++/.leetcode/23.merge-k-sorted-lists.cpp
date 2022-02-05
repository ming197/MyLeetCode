/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        auto cmp = [&](const ListNode* p1, const ListNode* p2){
            return p1->val > p2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto& p : lists){
            if(p != nullptr) q.push(p);
        }
        while (!q.empty())
        {
            /* code */
            if(q.size() == 1) {
                node->next = q.top();
                break;
            }
            node->next = q.top();
            node = q.top();
            q.pop();
            if(node->next != nullptr) q.push(node->next);
        }
        return head->next;
    }
};
// @lc code=end

