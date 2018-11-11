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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode * p = head;
        ListNode * q = dummy;
        dummy -> next = head;
        while(p)
        {
            while(p->val == q->val)
            {
                q -> next = p -> next;
                p = p -> next;
                if(!p)
                    break;
            }
            if(p)
            {
                p = p -> next; q = q -> next;
            }
        }
        return head;
    }
};
