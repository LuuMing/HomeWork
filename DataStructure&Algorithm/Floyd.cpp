void Floyd()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			D[i][j] = G[i][j];
			path[i][j] = -1;
		}
	for( k = 0; k < N; k++)
	{
		for(i = 0; i < N;i++)
		{
			for(j = 0; j < N;j++)
			{
				if(D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;
				}
			}	
		}
	}
}

