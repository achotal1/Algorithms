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