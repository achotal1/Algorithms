using namespace std;

#include <iostream>
#include <vector>

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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> onePath;
    findPathsRecursive(root, sum, onePath, allPaths);

    return allPaths;
  }
 private: 
  static void findPathsRecursive(TreeNode *root, int sum, vector<int> &onePath, vector<vector<int>> &allPaths){
    if(root == nullptr){
      return;
    }
    onePath.push_back(root->val);
    if(root->val == sum && root->left == nullptr && root->right == nullptr){
      allPaths.push_back(onePath);
    }
    else{
      findPathsRecursive(root->left, sum - root->val, onePath, allPaths);
      findPathsRecursive(root->right, sum - root->val, onePath, allPaths);
    }
    onePath.pop_back();
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
