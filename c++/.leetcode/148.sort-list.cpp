/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start

// Definition for singly-linked list.
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* p = head;
        queue<ListNode*> q;
        while (p)
        {
            /* code */
            q.push(p);
            p = p->next;
            q.back()->next = nullptr;
        }
        while (q.size() > 1)
        {
            /* code */
            int size = q.size();
            while (size > 1)
            {
                /* code */
                ListNode* h1 = q.front(); q.pop();
                ListNode* h2 = q.front(); q.pop();
                q.push(mergeTwoList(h1, h2));
                size -= 2;
            }
        }
        return q.front();
    }

    ListNode* mergeTwoList(ListNode* h1, ListNode* h2){
        ListNode* dummyHead = new ListNode();
        ListNode* prev = dummyHead;
        while (h1 && h2)
        {
            /* code */
            if(h1->val < h2->val){
                prev->next = h1;
                h1 = h1->next;
            }else{
                prev->next = h2;
                h2 = h2->next;
            }
            prev = prev->next;
        }
        prev->next = h1 ? h1 : h2;
        return dummyHead->next;
    }
};

int main(){
    int a[] = {4, 2, 1, 3};
    ListNode* dummy = new ListNode();
    ListNode* p = dummy;
    for(int& x : a){
        p->next = new ListNode(x);
        p = p->next;
    }
    Solution solution;
    solution.sortList(dummy->next);
    return 0;
}
// @lc code=end

