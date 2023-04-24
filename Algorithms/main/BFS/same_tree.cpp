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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> first;
        queue<TreeNode *> second;
        if(p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr || q == nullptr){
            return false;
        }
        first.push(p);
        second.push(q);
        while(!first.empty() && !second.empty()){
            int size = first.size();
            
            for(int i = 0; i<size; i++){
                TreeNode *x = first.front();
                TreeNode *y = second.front();
                first.pop();
                second.pop();
                if(x->val != y->val){
                    return false;
                }
                if(x->left != nullptr && y->left != nullptr){
                    first.push(x->left);
                    second.push(y->left);
                }else if(x->left != y->left){
                    return false;
                }
                if(x->right != nullptr && y->right != nullptr){
                    first.push(x->right);
                    second.push(y->right);
                }else if(x->right != y->right){
                    return false;
                }
            }
        }
        if(first.empty() != second.empty()){
            return false;
        }
        return true;
    }
    // via dfs
    bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr){
            return false;
        }else if(q == nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return isSameTreeDFS(p->left, q->left) && isSameTreeDFS(p->right, q->right);
    }
};