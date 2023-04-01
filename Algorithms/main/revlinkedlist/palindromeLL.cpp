// FIND IF LINKED LIST IS PALLINDROME OR NOT


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

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }
    bool var = true;
    ListNode *curr = head;
    
    ListNode *fast = head; ListNode *slow = head;
    
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *newNode = reverse(slow);
    ListNode *slow2 = newNode;
    while(newNode != nullptr && curr != nullptr){
      if(newNode->value != curr->value){
        var = false;
        break;
      }
      newNode = newNode->next;
      curr = curr->next;
    }
    reverse(slow2);
 
    return var;
  }
  static ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *temp = nullptr;
    while (head != nullptr) {
      temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }
    return prev;
  }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        if(head == nullptr){
            return true;
        }
        
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(prev == nullptr){
            return true;
        }
        prev->next = nullptr;
        ListNode *one = head;
        ListNode *second = reverse(slow);
        while(one != nullptr){
            if(one->val != second->val)
                return false;
            one = one->next;
            second = second->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *temp = nullptr;
        ListNode *curr = head;
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
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}
