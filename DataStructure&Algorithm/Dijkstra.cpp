void Dijkstra(Vetex S)
{
	dist= adj[S];
	while(1)
	{
		V = 未收录顶点中dist最小点;
		if( V not exist)
			break;
		collected[V] = True;
		for(V的每个邻接点W)
		{
			if(collected[W] == false)
			{
				if(dist[V] + adj[V][W] < dist[W])
				{
					dist[W] = dist[V] + adj[V][W];
					path[W] = V;
				 }	
			}
		}
	}
}
