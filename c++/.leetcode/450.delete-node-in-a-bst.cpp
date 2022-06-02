/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val == key){
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* curr = root->left;
            while (curr->right)
            {
                /* code */
                curr = curr->right;
            }
            curr->right = root->right;
            root = curr;
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
// @lc code=end

