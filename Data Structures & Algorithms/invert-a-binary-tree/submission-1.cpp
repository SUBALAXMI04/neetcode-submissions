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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;

        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            auto node = Q.front(); Q.pop();
            swap(node->right,node->left);
            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);
        }
        return root;



        // swap(root->left,root->right);
        // if(root->right) invertTree(root->right);
        // if(root->left) invertTree(root->left);
        // return root;
    }
};
