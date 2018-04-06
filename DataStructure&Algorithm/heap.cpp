#include<iostream>
using namespace std;
int heap[1001];
int N;
int M;
int size = 0;

void insert(int n)
{
	int pos = ++size;
	for(;heap[pos/2] > n; pos/=2)
		heap[pos] = heap[pos/2];
	heap[pos] = n; 	
}
void path(int i)
{
	for(; i!= 1;i/=2)
	{
		cout << heap[i]<<' ';
	}
	cout <<heap[i]<< endl;
}
int main()
{
	heap[0] = -10001;
	cin >> N >> M;
	for(int i = 0; i < N;i++)
	{
		int t;
		cin >> t;
		insert(t);
	}
	for(int i = 0; i < M;i++)
	{
		int t;
		cin >> t;
		path(t);
	}
}
