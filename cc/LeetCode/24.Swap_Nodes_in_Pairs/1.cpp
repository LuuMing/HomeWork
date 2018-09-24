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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * p = dummy;
        while(true)
        {
            bool flag = true;
            cout << p -> val << endl;
            if(p->next!=NULL)
            {
                ListNode * next_2 = p -> next -> next;
                if(p -> next -> next)
                { 
                    p -> next -> next = p -> next -> next -> next;
                }
                else
                {
                    break;
                }
                next_2 -> next = p -> next;
                p -> next = next_2;
                p = p -> next -> next;
            }
            else
                break;
        }
        return dummy -> next;
        
    }
};
