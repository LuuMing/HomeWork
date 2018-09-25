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
    ListNode * reverse_k(ListNode * head,int k)
    {
        ListNode * p = head -> next;
        ListNode * n = NULL;
        for(int i = 0; i < k; i++)
        {
            if(!p)
            {
                return head->next;
            }
            ListNode * tmp = p;
            p = p-> next;
            tmp -> next = n;
            n = tmp;
            if(i == k -1)
            {
                ListNode * returned = head -> next;
                head -> next -> next = p;
                head -> next = tmp;
                return returned;
            }
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy  = new ListNode(0);
        dummy -> next = head;
        ListNode * q = dummy;
        ListNode * p = dummy;
        bool flag = true;
        while(flag)
        {
            ListNode * p = q;
            for(int i = 0; i < k; i++)
            {
                if(!p)
                {
                    flag = false;
                    break;
                }
                p = p -> next;
            }
            if(!p)
            {
                flag = false;
                break;
            }
            q = reverse_k(q,k);  
        }
        return dummy -> next;
    }
};
