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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * dummy = new ListNode (-1);
        dummy -> next = head;
        ListNode * q = dummy, *p = head;
        while( p )
        {
            q -> next = p -> next;
            if( p -> next && p -> next -> next)
                p -> next = p -> next -> next;
            else
            {
                p -> next = dummy -> next;
                break;
            }
            q = q -> next;
            p = p -> next;
        }
        return head;
    }
};
