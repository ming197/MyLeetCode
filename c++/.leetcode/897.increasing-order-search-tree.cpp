/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        root->right = increasingBST(root->right);
        if(!root->left) return root;
        TreeNode* left = increasingBST(root->left);
        TreeNode* curr = left;
        while (curr->right)
        {
            /* code */
            curr = curr->right;
        }
        curr->right = root;
        root->left = nullptr;
        return left;
    }
};
// @lc code=end

