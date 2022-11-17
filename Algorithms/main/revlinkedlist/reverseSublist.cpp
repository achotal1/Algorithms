/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * DONE IN LEETCODE
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head;
        ListNode *temp = nullptr;
        ListNode *prev = nullptr;
        ListNode *firstNodeLL = curr;
        ListNode *nextToLeft = curr;
        if(left == right){
            return curr;
        }
       
        for(int i = 1; i< left; i++){
            if(i == (left - 1)){
                nextToLeft = curr;
            }
            curr = curr->next;
        }
        
        ListNode *firstNode = curr;
        int sub = right - left + 1;
        int c(0);
        while(c != sub){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            c++;
        }
        if(firstNode == nextToLeft){
            nextToLeft->next = curr;
            return prev;
        }
        else{
            firstNode->next = curr;
            nextToLeft->next = prev;
        }
        
        
        return firstNodeLL;
    }
};

/*
from __future__ import print_function


class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

  def print_list(self):
    temp = self
    while temp is not None:
      print(temp.value, end=" ")
      temp = temp.next
    print()


def reverse_sub_list(head, p, q):
  temp, prev, curr = None, None, head
  if p == q:
    return head
  i = 0
  while curr is not None and i<p-1: 
    prev = curr
    curr = curr.next
    i += 1
  last_node_of_first = prev
  last_node_of_sublist = curr
  i = 0
  while curr is not None and i< q - p + 1:
    temp = curr.next
    curr.next = prev
    prev = curr
    curr = temp
    i = i + 1
  
  last_node_of_first.next = prev
  last_node_of_sublist.next = curr

  return head


def main():
  head = Node(1)
  head.next = Node(2)
  head.next.next = Node(3)
  head.next.next.next = Node(4)
  head.next.next.next.next = Node(5)

  print("Nodes of original LinkedList are: ", end='')
  head.print_list()
  result = reverse_sub_list(head, 2, 4)
  print("Nodes of reversed LinkedList are: ", end='')
  result.print_list()


main()

*/