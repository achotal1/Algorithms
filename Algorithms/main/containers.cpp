using namespace std;

#include <iostream>


class TreeNode{
  public:
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    value = val;
    left = right = nullptr;
  }
  private:
  int value = 0;

}
class LinkedList{
  LinkedList* next;
  int value;
  LinkedList(int value){
    this->value = value;
    next = nullptr;
  }
}

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
}
