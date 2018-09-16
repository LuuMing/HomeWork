node * LCA(node * a, node * b)
{
	set<node*> s;
	while(a)
	{
		s.insert(a->val);
		a = a -> parent;
	}
	while(b)
	{
		if(s.count(b))
		{
			return b;
		}
		b = b->parent;
	}	
}
double * s2d(const char * str)
{
	int sign = 1;
	int idx = 0;
	if(str[idx] == '-')
	{
		sign = -1; idx++;
	}
	int a = 0;
	for(; str[idx] != '.' && str[idx] != 0; idx++)
		a = a*10 + (str[idx] - '0');
	if(str[idx] == 0)
		return (double) a;
	else
		idx++;
	int b = 0, weight = 1;
	for(; str[idx] != 0; idx++)
	{
		b = b* 10 + (str[idx] - '0');
		weight *= 10;
	}
	return (double) a + (double) b / weight;
}
node * merge(node * a, node * b)
{
	node * head = new node;
	head -> next = p;
	node * p = NULL;
	while(a && b)
	{
		if( a-> val > b -> val)
		{
			p = new node;
			*p = * b;
			p = p -> next;	
		}
		else
		{
			p = new node;
			*p = *a;
			p = p-> next;
		}
	}
	while(a)
	{
		p = new node;
		*p = *a;
		p = p -> next;
	}
	while(b)
	{
		p = new node;
		*p = *b;
		p = p -> next;
	}
	return head;
}
