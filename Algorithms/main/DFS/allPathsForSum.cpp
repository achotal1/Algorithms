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
    vector<int> v;
    // TODO: Write your code here
    findPathsRecursive(v, allPaths, root, sum);
    return allPaths;
  }
  static void findPathsRecursive(vector<int> &v, vector<vector<int>> &allPaths, TreeNode *root, int sum){
    if(root == nullptr){
      return;
    }
    sum -= root->val;
    v.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr){
      if(sum == 0)
        allPaths.push_back(v);
    }
    else{
      findPathsRecursive(v, allPaths, root->left, sum);
      findPathsRecursive(v, allPaths, root->right, sum);   
    }
    sum += root->val;
    v.pop_back();
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
