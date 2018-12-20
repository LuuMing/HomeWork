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
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(slow && fast)
        {
            slow = slow -> next;
            fast = fast -> next;
            if(fast)
                fast = fast -> next;
            if(slow == fast && slow)
                return true;
        }
        return false;
    }
};
