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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int size = 0;
    ListNode * Head;
    Solution(ListNode* head) {
        Head = head;
        for(; head; head = head -> next)
            size++;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ret;
        int prob = size;
        for(ListNode * p = Head; p; p = p -> next)
        {
            if(rand() / double(RAND_MAX) < 1.0 / prob--)
            {
                ret =  p -> val;
                break;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
