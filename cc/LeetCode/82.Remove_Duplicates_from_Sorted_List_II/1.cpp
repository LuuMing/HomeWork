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
        ListNode * q = new ListNode(-1);
        ListNode * p = head;
        ListNode * dummy = q;
        q -> next = p;
        bool flagDup = false;
        while(true)
        {
            bool flagLop = false;
            while(p && p -> next && p-> val == p -> next -> val)
            {
                p = p -> next;
                flagLop = true;
                flagDup = true;
            }    
            if(flagLop)
            {
                p = p -> next;
                continue;
            }
            else
            {
                if(flagDup)
                {
                    flagDup = false;
                    q -> next = p;
                }
                if(p)
                {
                    q = q -> next;
                    p = p -> next;
                }
                else
                    break;
            }
        }
        return dummy -> next;
    }
};