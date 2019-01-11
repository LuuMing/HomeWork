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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> s;
        while( headA ||  headB )
        {
            if(headA && s.count(headA))
                return headA;
            else
                s.insert(headA);
             if(headB&& s.count(headB) )
                return headB;
            else
                s.insert(headB);
            if( headA )  headA = headA -> next;
            if( headB )   headB = headB -> next;
            
        }
        return NULL;
    }
};