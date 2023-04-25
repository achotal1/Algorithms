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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *front = nullptr;
        ListNode *back = nullptr;
        int curr = 0;
        while(head != nullptr){
            if(head->val == 0){
                if(curr > 0){
                    ListNode *val = new ListNode(curr);
                    if(front == nullptr){
                        front = val;
                        back = val;
                    }else{
                        back->next = val;
                        back = val;
                    }
                    curr = 0;
                }
            }else{
                curr += head->val;
            }
            head = head->next;
        }
        return front;

        
    }
};