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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums, 0, nums.size() - 1);
    }
    TreeNode * recursive(vector<int>& nums, int first, int last){
        if(first>last){
            return nullptr;
        }
        int half = (last + first)/2;
        TreeNode *ans = new TreeNode(nums[half]);
        ans->left = recursive(nums, first, half - 1);
        ans->right = recursive(nums, half + 1, last); 
        return ans;     
    }
};