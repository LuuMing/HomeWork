void TopSort()
{
	for(图中每个顶点 V)
		if(Indegree[v] == 0)
			Enqueue(v,Q);
	while( !IsEmpty(Q) )
	{
		V = Dequeue(Q);
		输出V，或者记录V的输出序号; cnt++;
		for(V 的每个邻接节点W)
			if( --Indegree[W]==0 )
				Enqueue(W,Q);
	}
	if( cnt != |V| )
		Error("图中有回路");
}
