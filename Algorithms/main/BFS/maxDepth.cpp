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
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        if(root == nullptr){
            return 0;
        }
        q.push(root);
        int count = 0;
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode *tn = q.front();
                q.pop();
                if(tn->left != nullptr){
                    q.push(tn->left);
                }
                if(tn->right != nullptr){
                    q.push(tn->right);
                }
            }
        }
        return count;
    }
   
};