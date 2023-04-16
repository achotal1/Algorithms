class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertRecursive(root);
        return root;
    }
    void invertRecursive(TreeNode *root){
        if(root == nullptr){
            return;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
    }
};