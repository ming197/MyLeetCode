/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
class Solution {
    TreeNode *first, *second, *prev;
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode *root) {
        if(!root) return;
        
        inorder(root->left);
        
        if(!first && root->val < prev->val) first = prev;
        if(first && root->val < prev->val) second = root;
        prev = root;
        
        inorder(root->right);
    }
};
// @lc code=end

