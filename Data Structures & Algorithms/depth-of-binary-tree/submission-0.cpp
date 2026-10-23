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
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int cnt = 0;
        while(!Q.empty()){
            int len = Q.size();
            while(len--){
                auto node = Q.front(); Q.pop();
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            cnt++;
        }
        return cnt;
    }
};
