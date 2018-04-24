void Unweighted(Vertex S)
{
	Enqueue(S,Q);
	while(!Q.empty())
	{
		V = Dequeue(Q);
		for(W :each adjacent vertex of V)
		{
			if(dist[W] == -1)
			{
				dist[W] = dist[V] + 1;
				path[W] = V;
				Enqueue(W,Q);
			}
		}
	}
}
