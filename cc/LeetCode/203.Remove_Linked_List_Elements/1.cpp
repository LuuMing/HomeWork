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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode * p = head,*q = dummy;
        while(p)
        {
            if(p -> val == val)
            {
                q -> next = p -> next;
            }
            else
            {
                q = q -> next;
            }
            p = p -> next;
            
        }
        return dummy -> next;
    }
};