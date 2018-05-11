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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  	ListNode * head = new ListNode(0);
	ListNode * cur = head,*p = l1,*q = l2;
	int jinwei = 0;
	int remain = 0;
	while(p||q) 
	{
		
		int sum = (p?p->val:0)+(q?q->val:0) + jinwei;
		jinwei = sum / 10;
		remain = sum % 10;
		cur -> next =new ListNode(remain);
		cur = cur -> next;
		if(p)
			p = p->next;
		if(q)
			q = q->next;
	}
	if(jinwei != 0)
	{
		cur ->next =new ListNode(jinwei);
	}
	return head->next;	 		 
    }
};
