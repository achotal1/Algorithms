using namespace std;
#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class findStartofCycle {
 private:
  static int findLength(ListNode *p1, ListNode *p2){
    p2 = p2->next;
    int length = 1;
    while(p1 != p2){
      p2 = p2->next;
      length++;
    }
    return length;
  }
 public:
  static ListNode *findCycleStart(ListNode *head) {
    ListNode *p1(head),*p2(head);
    int cycleLength = 0;
    while(p2 != nullptr && p2->next != nullptr){
      p1 = p1->next;
      p2 = p2->next->next;
      if(p1 == p2){
        cout<<"Cycle Found\n";
        cycleLength = findLength(p1,p2);
        break;
      }
    }
    p1 = head;
    p2 = head;
    // move p2 to the length of the cycle 
    for(int i = 0;i<cycleLength;i++){
      p2 = p2->next;
    }
    while(p2 != p1){
      p1 = p1->next;
      p2 = p2->next;
    }

    return p1;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << findStartofCycle::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << findStartofCycle::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << findStartofCycle::findCycleStart(head)->value << endl;
}
