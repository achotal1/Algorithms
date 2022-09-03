using namespace std;

#include <iostream>
#include <queue>

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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q; 
    if(root == nullptr){
      return result;
    }

    q.push(root);
    while(!q.empty()){
      int levelsize = q.size();
      vector<int> res;
      for(int i = 0; i<levelsize;i++){
        TreeNode *tn = q.front();
        res.push_back(tn->val);
        q.pop();
        if(tn->left != nullptr){
          q.push(tn->left);
        }
        if(tn->right != nullptr){
          q.push(tn->right);
        }
      }
      result.push_back(res);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
