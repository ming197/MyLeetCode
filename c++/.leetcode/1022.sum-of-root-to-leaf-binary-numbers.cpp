/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
class Solution {
public:
    vector<int> num; 
    int res = 0;
    int sumRootToLeaf(TreeNode* root) {
            
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        num.emplace_back(root->val);
        if(!root->left && !root->right){
            res += cal();
        }
        dfs(root->left);
        dfs(root->right);
        num.pop_back();
    }
    int cal(){
        int x = 0;
        for(int i = 0; i < num.size(); i++){
            x <<= 1;
            x += num[i];
        }
        return x;
    }
};
// @lc code=end

