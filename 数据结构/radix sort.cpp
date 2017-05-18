#include<iostream>
#include<vector>
#include<list>
using namespace std;
template<class T>
void ShellSort(T *data , int len)
{
	
} 


int main()
{
	list<int>n[10];//基数排序的10个桶 
	int b[10] = { 278, 109, 063, 930, 589, 184, 505, 269, 8, 83 };//待排数组 
	list<int> temp; //临时队列 
	for( int i = 0 ;i <10 ; i++ )
	{
			n[ b[i]%10 ].push_front( b[i] );//以个位数为基准入队列 
	}
		
	for(int i = 9 ; i >= 0 ;i--)
		{
			while( !n[i].empty() )
			{
				temp.push_front( n[i].front() );
				n[i].pop_front(); 
			}
		}
		while(!temp.empty())
		{
			cout<< temp.front()<<endl;
			temp.pop_front();
		}
		//基数排序第一步，未完待续 
}
