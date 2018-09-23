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
        static bool cmp( ListNode*   L1,  ListNode*  L2) 
        {
            if(L1 == NULL)
                return false;
            else if( L2 == NULL)
                return true;
            return L1 -> val > L2->val;
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            ListNode * dummy = new ListNode(0);
            ListNode * p = dummy;
            while(!lists.empty())
            {
                make_heap(lists.begin(),lists.end(),cmp);  
                if(lists[0] != NULL) 
                {
                    p -> next = lists[0];
                    lists[0] = lists[0]->next;
                    p = p -> next;
                }
                else
                    lists.erase(lists.begin());
            }

            return dummy -> next;
        }
    };
