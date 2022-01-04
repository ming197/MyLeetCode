/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* prev = dummyHead;
        int carry = 0;
        while(l1 || l2){
            int x = 0, y = 0;
            if(l1){
                x = l1->val;
                l1 = l1->next;
            }
            if(l2){
                y = l2->val;
                l2 = l2->next;
            }
            int sum = x + y + carry;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            carry = sum / 10;
        }
        if(carry == 1) prev->next = new ListNode(1);
        return dummyHead->next;
    }
};
// @lc code=end

