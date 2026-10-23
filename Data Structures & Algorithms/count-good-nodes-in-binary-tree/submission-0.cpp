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
    int goodNodes(TreeNode* root){
        if(!root) return 0;
        int cnt = 0;
        queue<pair<TreeNode*,int>> Q;
        Q.push({root,root->val});
        while(!Q.empty()){
            auto [node,val] = Q.front(); Q.pop();
            if(val <= node->val) cnt++;
            if(node->left) Q.push({node->left,max(val,node->left->val)});
            if(node->right) Q.push({node->right,max(val,node->right->val)});
        }
        return cnt;
    }
};
