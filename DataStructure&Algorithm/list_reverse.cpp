#include<iostream>
using namespace std;
struct node
{
	int data;
	node * next;
};
node * build()
{
	int N;
	node * head = new node;
	node* p = head;
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		node * s = new node;
		cin >> s->data;
		p->next = s;
		p = s;
	}
	return head;
}
void output(node * head)
{
	node * p = head -> next;
	while(p)
	{
		cout << p->data <<' ';
		p = p->next;
	}
	cout << endl;
}
node * reverse(node * head)
{
	node * newnode = NULL;
	node * p = head->next;
	while(p)
	{
		node * temp = p->next;
		p -> next = newnode;
		newnode = p;
		p = temp;	
	}
	head -> next = newnode;
	return head;
}
int main()
{
	node * head = build();
	output(head);
	node * reversed = reverse(head);
	output(reversed);
}
