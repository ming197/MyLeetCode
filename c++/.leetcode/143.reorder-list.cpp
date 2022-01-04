/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode* l1 = head, *l2 = head->next;
        ListNode* p = l1, *q = l2;
        // find middle
        while (q->next&&q->next->next)
        {
            /* code */
            p = p->next;
            q = q->next->next;
        }
        if(q->next){
            l2 = p->next->next;
            p->next->next = nullptr;
        }else {
            l2 = p->next;
            p->next = nullptr;
        }
        
        // reverse l2
        ListNode* prev = nullptr;
        ListNode* curr = l2;
        while (curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l2 = prev;
        // merge l1 and l2
        p = l1;q = l2;
        while (q)
        {
            ListNode* next1 = p->next;
            ListNode* next2 = q->next;
            p->next = q;
            q->next = next1;
            p = next1;
            q = next2;
        }
    }
};
// @lc code=end

