/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
private:
    int max_freq = -1;
    unordered_map<int, int> val2Freq;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for(auto it = val2Freq.begin(); it != val2Freq.end(); it++){
            if(it->second == max_freq) res.emplace_back(it->first);
        }
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int val = root->val + dfs(root->left) + dfs(root->right);
        val2Freq[val]++;
        max_freq = max( max_freq, val2Freq[val]);
        return val;
    }
};
// @lc code=end

