/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        dfs(root1, nums1);
        dfs(root2, nums2);
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            /* code */
            int x = 1e5 + 10, y = 1e5 + 10;
            if(i < nums1.size()){
                x = nums1[i];
            }
            if(j < nums2.size()){
                y = nums2[j];
            }
            if(x < y){
                res.emplace_back(x);
                i++;
            }else{
                res.emplace_back(y);
                j++;
            }
        }
        return res;
    }
    void dfs(TreeNode* root, vector<int>& nums){
        if(!root) return;
        dfs(root->left, nums);
        nums.emplace_back(root->val);
        dfs(root->right, nums);
    }
};
// @lc code=end

