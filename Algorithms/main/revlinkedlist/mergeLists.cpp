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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        if(list1 == nullptr){
            return list2;
        }
        else if(list2 == nullptr){
            return list1;
        }
        ListNode *curr = nullptr;
        if(list1->val >= list2->val){
            curr = list1;
            list1 = list1->next;
        }
        else{
            curr = list2;
            list2 = list2->next;
        }
        ListNode *head = curr;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                head->next = list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
            
        }
        if(list1 == nullptr){
            head->next = list2;
        }
        else{
            head->next = list1;
        }
        return curr;

    }
};