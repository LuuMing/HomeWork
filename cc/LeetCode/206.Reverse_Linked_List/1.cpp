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
    ListNode* reverseList(ListNode* head) {
        ListNode * newnode = NULL;
        while(head)
        {
            ListNode * tmp = head -> next;
            head -> next = newnode;
            newnode = head;
            head = tmp;
        }
        return newnode;
    }
};