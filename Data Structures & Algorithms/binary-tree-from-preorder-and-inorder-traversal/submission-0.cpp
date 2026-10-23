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
    unordered_map<int,int> mp;
    int preIdx = 0;
    TreeNode* build(int inL,int inR,vector<int>& preorder){
        if(inL > inR) return NULL;
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        int mid = mp[val];
        root->left = build(inL,mid - 1,preorder);
        root->right = build(mid + 1,inR,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
        for(int i = 0;i < inorder.size();i++) mp[inorder[i]] = i;
        return build(0,inorder.size() - 1,preorder);
    }
};
