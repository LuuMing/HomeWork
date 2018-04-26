void TopSort()
{
	for(cnt = 0; cnt < V; cnt++)
	{
		V = 未输出入度为0的顶点;
		if(V not exist)
		{
			Error("有环");
			break;
		}
		输出V，或者记录V的输出序号;
		for(V的每个邻接点W)
		{	
			Indegree[W]--；
		}
	}
}
