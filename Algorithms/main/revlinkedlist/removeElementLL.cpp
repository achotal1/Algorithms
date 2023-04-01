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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        if(head == nullptr){
            return nullptr;
        }
        
        while(curr != nullptr){
            if(curr->val == val){
                ListNode *temp = curr;
                if(curr == head){
                    curr = curr->next;
                    head = head->next;
                    temp->next = nullptr;
                }
                else{
                    curr = curr->next;
                    prev->next = curr;
                    temp->next = nullptr;
                }     
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};