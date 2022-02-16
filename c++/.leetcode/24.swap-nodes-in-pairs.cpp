/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next&&p->next->next)
        {
            /* code */
            ListNode* next = p->next;
            p->next = next->next;
            next->next = next->next->next;
            p->next->next = next;
            p = next->next;
        }
        return dummy->next;
    }
};
// @lc code=end

