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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        else if(!root || !subRoot){
            return false;
        }

        if(root->val == subRoot->val){
            if(checkSub(root, subRoot)){
                return true;
            }
        }
            
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool checkSub(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }
        else if(!subRoot || !root){
            return false;
        }

        if(root->val == subRoot->val){
            bool a = checkSub(root->left, subRoot->left);
            bool b =  checkSub(root->right, subRoot->right);
            return a && b;
        }else{
            return false;
        }

        return true;
    }
};