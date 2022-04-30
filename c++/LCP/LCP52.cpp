#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    set<int> st;

    void dfs(TreeNode *node) {
        if (node == nullptr) return;
        st.insert(node->val);
        dfs(node->left);
        dfs(node->right);
    }

public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int ans = 0;
        for (int i = (int) ops.size() - 1; i >= 0; i--) {
            while (true) {
                auto it = st.lower_bound(ops[i][1]);
                if (it == st.end() || (*it) > ops[i][2]) break;
                st.erase(it);
                if (ops[i][0]) ans++;
            }
        }
        
        return ans;
    }
};


// class Solution {
// public:
//     vector<pair<int, int>> nodes;
//     int getNumber(TreeNode* root, vector<vector<int>>& ops) {
//         dfs(root);
//         for(auto& op : ops){
//             int low = op[1], high = op[2], color = op[0];
//             int l = 0, r = nodes.size() - 1;
//             // find first node's val >= low
//             while (l < r){
//                 /* code */
//                 int mid = l + (r - l >> 1);
//                 if(nodes[mid].first < low){
//                     l = mid + 1;
//                 }else r = mid;
//             }
//             int i = l;
//             // find last node's val <= high
//             r = nodes.size() - 1;
//             while (l < r){
//                 /* code */
//                 int mid = l + (r - l + 1 >> 1);
//                 if(nodes[mid].first > high){
//                     r = mid - 1;
//                 }else{
//                     l = mid;
//                 }
//             }
//             int j = l;
//             for(int k = i; k <= j; k++) nodes[k].second = color;
//         }
//         int res = 0;
//         for(auto& node : nodes){
//             res += node.second;
//         }
//         return res;
//     }

//     void dfs(TreeNode* root){
//         if(!root) return;
//         dfs(root->left);
//         nodes.emplace_back(make_pair(root->val, 0));
//         dfs(root->right);
//     }
// };