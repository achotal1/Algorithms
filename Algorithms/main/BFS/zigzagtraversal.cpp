using namespace std;

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    deque<TreeNode *> deq;
    int flag(0);
    if(root == nullptr){
      return result;
    }
    deq.push_back(root);
    while(!deq.empty()){
      int levelsize = deq.size();
      vector<int> v;
      for(int i = 0; i<levelsize; i++){
        TreeNode *fr = deq.front();
        deq.pop_front();
        v.push_back(fr->val);
        if(fr->left != nullptr){
          deq.push_back(fr->left);
        }
        if(fr->right != nullptr){
          deq.push_back(fr->right);
        } 
      }
      if(flag == 0){
        result.push_back(v);
      }
      else{
        reverse(v.begin(),v.end());
        result.push_back(v);
      }
      if(flag == 0){
        flag = 1;
      }
      else{
        flag = 0;
      }
      
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
