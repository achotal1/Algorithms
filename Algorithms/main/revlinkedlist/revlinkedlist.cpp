using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int val) {
    value = val;
    next = nullptr;
  }
};

class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *temp = nullptr;
    while(curr != nullptr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);

  ListNode *result = ReverseLinkedList::reverse(head);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}