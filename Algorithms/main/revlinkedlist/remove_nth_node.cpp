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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = head;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        if(head == nullptr)return nullptr;
        int i = 0;int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        int n2 = size - n + 1;
        while(start){
            i++;
            if(i == n2){
                if(prev == nullptr){
                    if(start->next != nullptr)
                    head = start->next;
                    else return nullptr;
                }          
                else{
                    cout<<start->val<<endl;
                    ListNode *temp = start;
                    if(start->next == nullptr){
                        prev->next = nullptr;
                    }else{
                        prev->next = start->next;
                    }  
                }
                break;
            }else{
                prev = start;
                start = start->next;
            }
        }
        return head;
    }
};