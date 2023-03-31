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
        queue<TreeNode *> q;
        if(root == nullptr)
            return nullptr;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode *tn = q.front();
                q.pop();
                TreeNode *temp = tn->left;
                tn->left = tn->right;
                tn->right = temp;
                if(tn->left != nullptr){
                    q.push(tn->left);
                }
                if(tn->right != nullptr){
                    q.push(tn->right);
                }
            }
        } 
        return root;
    }
};