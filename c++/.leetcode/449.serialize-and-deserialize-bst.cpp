/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // string in_order;
    string pre_order;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preOrder(root);
        return pre_order;
    }


    void preOrder(TreeNode* root){
        if(root == nullptr) return;
        pre_order += to_string(root->val) + "#";
        preOrder(root->left);
        preOrder(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vec;
        int i = 0;
        int n = data.size();
        while (i < n)
        {
            int j = i;
            while(j < n && data[j] != '#'){
                j++;
            }
            vec.emplace_back(stoi(data.substr(i, j - i)));
            i = j + 1;
        }
        return pre2Tree(vec, 0, vec.size() - 1);
    }

    TreeNode* pre2Tree(vector<int>& vec, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(vec[l]);

        int val = vec[l];

        // first > val
        int i = l + 1;

        while (i <= r)
        {
            /* code */
            if(vec[i] < val) i++;
            else break;
        }
        TreeNode* root = new TreeNode(val);
        root->left = pre2Tree(vec, l + 1, i - 1);
        root->right = pre2Tree(vec, i, r);
        return root; 
        
    }
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Codec codec;
    string tree = codec.serialize(root);
    TreeNode* ans = codec.deserialize(tree);
}

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

