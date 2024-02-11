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
    bool isValidBST(TreeNode* root) {
        long long min = std::numeric_limits<long long>::min();
        long long max = std::numeric_limits<long long>::max();
        return isValid(root, min, max);
    }
    bool isValid(TreeNode * root, long long l, long long r){
        if(root == nullptr)return true;
        if(root->val > l && root->val < r){
            return isValid(root->left, l, root->val) and 
                   isValid(root->right, root->val, r);

        }else{
            return false;
        }
    }
};