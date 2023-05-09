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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        pair<ListNode*, int>  p1 = reverseSum(l1);
        pair<ListNode*, int>  p2 = reverseSum(l2);
        int sum = p1.second + p2.second;
        ListNode *res = new ListNode(sum%10);
        ListNode *res2 = res;
        sum /= 10;
        while(sum > 0){
            res->next = new ListNode(sum%10);
            sum /= 10;
            res = res->next;
        }

        return res2; 
    }
    pair<ListNode *, int> reverseSum(ListNode *LL){
        ListNode *temp = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = LL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *trav = prev;
        int sum = 0;
        int i = 0;
        
        while(trav){
            sum += trav->val*pow(10,i);
            trav = trav->next;
            i++;
        }
        return make_pair(prev, sum);
    }
};