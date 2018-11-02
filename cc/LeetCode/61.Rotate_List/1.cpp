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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * p = dummy;
        ListNode * q = dummy;
        ListNode * tmp = head;
        int length = 0;
        while(tmp)
        {
            length ++;
            tmp = tmp-> next;
        }
        k = k % length;
        while(k--)
        {
            p = p -> next;
            if(!p)
            {
                p = head;
            }
        }
        while( p-> next)
        {
            p = p -> next;
            q = q -> next;
            if(!q)
                q = dummy;
        }
        if(q != dummy)
        {
            cout << q -> val;
            p -> next = head;
            ListNode * result = q -> next;
            q -> next = NULL;
            return result;
        }
        else
            return head;
    }
};
