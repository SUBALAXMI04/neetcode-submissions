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

class Codec {
public:

    string serialize(TreeNode* root){
        if(!root) return "N";
        queue<TreeNode*> Q;
        Q.push(root);
        string ans = "";
        while(!Q.empty()){
            auto node = Q.front(); Q.pop();
            if(!node) ans += "N,";
            else{
                ans += to_string(node->val) + ",";
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        return ans;
    }

    TreeNode* deserialize(string data){
        string val = "";
        stringstream ss(data);
        getline(ss,val,',');
        if(val == "N") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> Q;
        Q.push(root);
        while(getline(ss,val,',')){
            auto node = Q.front(); Q.pop();
            if(val != "N"){
                node->left = new TreeNode(stoi(val));
                Q.push(node->left);
            }
            getline(ss,val,',');
            if(val != "N"){
                node->right = new TreeNode(stoi(val));
                Q.push(node->right);
            }
        }
        return root;
    }
};
