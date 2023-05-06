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
        if(root == nullptr) return false;
        if(isSameTree(root, subRoot)){
            return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left|right;
    }
    bool isSameTree(TreeNode *root, TreeNode *subRoot){
        if(root == nullptr && subRoot == nullptr){
            return true;
        }else if(root == nullptr || subRoot == nullptr){
            return false;
        }
        if(root->val == subRoot->val){
            return isSameTree(root->left, subRoot->left) && 
                   isSameTree(root->right, subRoot->right);
        }else
            return false;

    }
};