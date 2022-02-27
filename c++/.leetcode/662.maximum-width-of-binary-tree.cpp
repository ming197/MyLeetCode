/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        unsigned int ans = 0 ;
        queue<pair<TreeNode*, int>> q ;
        q.push({root,0}) ;
		// bfs ( level order traversal )
        while(!q.empty()){
            int size = q.size() ;
            int min = q.front().second ;
            unsigned int first, last ;
            for(int i = 0 ; i < size ; i++){
                unsigned int cur = q.front().second - min ;
                TreeNode* node = q.front().first ;
                q.pop() ;
                if(i == 0) first = cur ;
                if(i == size - 1) last= cur ;               
				// pushing left child subtree
                if(node -> left) q.push({node -> left , 2*cur + 1 }) ;
				// pushing right child subtree
                if(node -> right) q.push({node -> right , 2*cur + 2 }) ;
            }
            ans = max(ans , last - first + 1) ;
        }
        return ans ;
    }
};
// @lc code=end

