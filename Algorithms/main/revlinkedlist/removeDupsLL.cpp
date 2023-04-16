#include "LinkedList.h"
#include <unordered_map>
string LinkedList::removeDuplicates() {  
  unordered_map<int,int> map;
  Node *trav = head;
  Node *prev = head;
 
  Node *first = head;
  for(int i = 0; i<length(); i++){
    map[trav->data]++;
    //cout<<i<<" "<<trav->data<<endl;
    if(map[trav->data] > 1){
      cout<<i<<endl;
      Node *temp = trav;
      if(trav->nextElement == nullptr){
        prev->nextElement = nullptr;
        cout<<"PLS";
        map[temp->data]--;
        delete(temp);
        break;
      }
      trav = trav->nextElement;
      prev->nextElement = trav;
      map[temp->data]--;
      
      if(map[temp->data] == 0){
        map.erase(temp->data);
      }
      delete(temp);
    }
    else{
      //cout<<trav->data<<" ";

      cout<<i<<endl;
      prev = trav;
      if(trav->nextElement == nullptr){
        trav = nullptr;
      }
      else
      trav = trav->nextElement;
    }
  }
  Node *newnode = head;
  while(newnode != nullptr){
    cout<<newnode->data<<" ";
    newnode = newnode->nextElement;
  }
  
  return elements();
}

/**
 * Sorted LinkedList remove dups
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head->next;
        ListNode *prev = head;
        if(prev == nullptr){
            return nullptr;
        }
        while(curr != nullptr){
            if(curr->val == prev->val){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
            
        }
        return head;
    }
    ListNode* deleteDups2(ListNode *head){
      if(head == nullptr){
            return head;
        }
        ListNode *curr = head;
        while(curr  && curr->next ){
            if(curr->val == curr->next->val){
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }
            
        }

        return head;
    }
};