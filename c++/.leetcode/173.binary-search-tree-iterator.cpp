/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* curr;
    BSTIterator(TreeNode* root) {
        curr = root;
        while (curr->left)
        {
            /* code */
            stk.push(curr);
            curr = curr->left;
        }
        curr->left = new TreeNode(-1);
        stk.push(curr);
        curr = curr->left;
    }
    
    int next() {
        if(curr->right){
            curr = curr->right;
            while (curr->left){
                /* code */
                stk.push(curr);
                curr = curr->left;
            }
        }else{
            curr = stk.top();
            stk.pop();
        }
        return curr->val;
    }
    
    bool hasNext() {
        return curr->right || !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

