using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    int totalPathsSum = 0;
    vector<int> digits;
    findPathRecursive(root, digits, totalPathsSum);
    return totalPathsSum;
  }
 private:
  static void findPathRecursive(TreeNode *root, vector<int> &digits, int &sum){
    if(root == nullptr)
    return;
    digits.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr){
        sum += calculateSum(digits);
    }
    else{
        findPathRecursive(root->left, digits, sum);
        findPathRecursive(root->right, digits, sum);
    }
    digits.pop_back();

  }
  static int calculateSum(vector<int> &digits){
    int sum = 0;
    int i = digits.size() - 1;
    for(auto &a : digits){
        sum += pow(10, i) * a;
        i--;
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
