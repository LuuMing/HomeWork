#include<iostream>
using namespace std;
int main()
{
	int length = 0;
	string data;
	getline(cin,data);
	int type = 0;
	for(int i = 0; i < data.size(); i++)
	{	
		for(int j =0; i-j >=0&&i+j+1<data.size(); j++)				//轴对称
		{
			if(data[i-j]!=data[i+j+1])		                        //1 2 2 1
			{
				break;
			}
			else
			{
				if(2*(j+1) > length)
				{
					length = 2*(j+1);
				}
			}
		}
		for(int j = 0; i-j >=0 && i + j < data.size();j++)                      //中心对称
		{
			if(data[i+j] != data[i-j])                                      //1 2 0 2 1
			{
				break;	
			}
			else
			{
				if( 2*j+1 > length )
				{
					length = 2*j+1;
				}
			}
		}
	}
	if (data.size()==1)
	{
		cout << 1;
		return 0;
	}
	cout << length;
}
