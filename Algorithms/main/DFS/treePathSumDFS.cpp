/* 
Binary tree path sum should be equal to sum given
*/

using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    TreeNode *tn = root;
    if(tn == nullptr){
      return false;
    }
    if(tn->left == nullptr && tn->right == nullptr && tn->val == sum){
      return true;
    }
   

    return hasPath(tn->left,sum - tn->val ) || hasPath(tn->right, sum - tn->val);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}
