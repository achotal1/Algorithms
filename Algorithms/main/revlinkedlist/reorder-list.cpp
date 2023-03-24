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
    void reorderList(ListNode* head) {
        if(head->next == nullptr){
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *one = head;
        ListNode *two = reverse(slow);
        merge(one, two);
    }
    ListNode *reverse(ListNode *h){
        ListNode *prev = nullptr;
        ListNode *curr = h;
        ListNode *temp = nullptr;
        while(curr != nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void merge(ListNode *one, ListNode *two){
        ListNode *trav = one;

        while(one != nullptr){
            ListNode *first = one->next;
            ListNode *second = two->next;
            one->next = two;
            if(first == nullptr){
                break;
            }
            two->next = first;
            one = first;
            two = second;
        }
    }
};



