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
    ListNode* partition(ListNode* head, int x) {
        ListNode * less = new ListNode(-1), * greater = new ListNode(-1);
        ListNode * l = less, *g = greater;
        for(ListNode * p = head; p ; p = p -> next)
        {
            if( p -> val < x)
            {
                l -> next = p;
                l = l -> next;
            }
            else
            {
                g -> next = p;
                g = g -> next;
            }
        }
        g -> next = NULL;
        l -> next = greater-> next;
        return less -> next;
    }
};
