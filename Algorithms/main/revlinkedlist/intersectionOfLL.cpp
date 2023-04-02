/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode *currA = headA;
        ListNode *currB = headB;
        while(currA != nullptr){
            sizeA++;
            currA = currA->next;
        }
        while(currB != nullptr){
            sizeB++;
            currB = currB->next;
        }
        ListNode *res = nullptr;
        if(sizeA > sizeB){
            ListNode *travA = trav(sizeA - sizeB, headA);
            res = intersect(travA, headB);
        }
        else if(sizeB > sizeA){
            ListNode *travB = trav(sizeB - sizeA, headB);
            res = intersect(headA, travB);
        }
        else{
            res = intersect(headA, headB);
        }
        return res;
    }
    ListNode *trav(int count, ListNode *head){
        ListNode *curr = head;
        while(count != 0){
            curr = curr->next;
            count--;
        }
        return curr;
    }
    ListNode *intersect(ListNode *A, ListNode *B){
        ListNode *currA = A;
        ListNode *currB = B;
        while(currA != nullptr){
            if(currA == currB){
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }

};