using namespace std;

#include <iostream>
/* 
FIND MIDDLE OF LINKED LIST 
If size of linked list is even find the second number 
*/
class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class MiddleOfLinkedList {
 public:
  static ListNode *findMiddle(ListNode *head) {
    ListNode *p1(head),*p2(head);
  /* BRUTE FORCE:
  
    int size = 0;
    while(p1 != nullptr){
      p1 = p1->next;
      size++;
    }
    int i = 1;
    size = size/2 + 1;
    while(i != size){
      p2 = p2->next;
      i++;
    }
    return p2;
  */
   while(p1 != nullptr && p1->next != nullptr){
     p1 = p1->next->next;
     p2 = p2->next;
   }
   return p2;

  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;
}
