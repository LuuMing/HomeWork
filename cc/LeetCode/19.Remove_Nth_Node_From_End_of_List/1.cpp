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
    bool solve(ListNode * p,int n)
    {
        for(int i = 0; i < n;i++)
        {
            if(p)
                p = p -> next;
           else
               return false;
        }
        if (p == NULL)
            return true;
        else
            return false;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode * q = new ListNode(0);
        ListNode * t = q;
        
        q -> next = head;
        for(; q != NULL; q = q -> next)
        {
            if(solve(q -> next, n))
            {
                q -> next = q -> next -> next;
                return t -> next;
            }
        }
    }
};
