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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        int cleanup = diameterRecursive(root, maxDiam);
        return maxDiam;
    }
    int diameterRecursive(TreeNode *root, int& maxDiam){
        if(root == nullptr){
            return 0;
        }
        int left = diameterRecursive(root->left, maxDiam);
        int right = diameterRecursive(root->right, maxDiam);
        maxDiam = max(maxDiam, left + right);
        return 1 + max(left, right);
    }
};