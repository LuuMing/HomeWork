int merge(int* array1,int len1, int *array2, int len2, int * array3)
{
	int i = 0, j = 0, p = 0;
	while( i < len1 && j < len2)
	{
		if( array1[i] < array2[j])
		{
			array3[p++] = array1[i++];
		}		 
		else
		{
			array3[p++] = array2[j++];
		}
	}
	if( i < len1)
		for(; i < len1; i++) array3[p++] = array1[i];
	if(j < len2)
		for(; j < len2; j++) array3[p++] = array2[j];
}
