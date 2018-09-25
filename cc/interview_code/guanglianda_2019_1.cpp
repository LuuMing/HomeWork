/*
	田忌赛马
*/
void HourseRacing(String [] tianji,String [] qiweiwang)
{
	for(int i = 0 ; i < 3; i++)
	{
		cout << tianji[i] <<" vs " << qiweiwang[(i+1) %3];
	}
}
