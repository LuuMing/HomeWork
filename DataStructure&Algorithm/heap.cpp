#include<iostream>
using namespace std;
int heap[1001];
int N;
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
int Delete()
{
	int parent,child;
	int minitem = heap[1];   //取出最小值
	int temp = heap[size--];//用最小堆最后一个元素从根节点向上过滤
	for(parent = 1; parent * 2 <= size /*has left?*/; parent = child)
	{
		child = 2 * parent; 
		if(child != size &&  heap[child+1] < heap[child]) //有无有右儿子,有的话找最小child
		{
			child = child + 1;
		}
		if(temp < heap[child])	break;    //位置合适 break
		else
			heap[parent] = heap[child];//否则,上滤
		
	}
	heap[parent] = temp;
	return minitem;
}
int main()
{
	heap[0] = -10001;
	cin >> N ;
	for(int i = 0; i < N;i++)
	{
		int t;
		cin >> t;
		insert(t);        // test insert
		cout << "插入 "<< t << endl  << "heap: ";
		for(int i = 1; i <= size; i++)
			cout << heap[i] <<" ";
		cout << endl;
	}
	cout << "删除" << endl;
	for(int i = 0; i < N;i++)
	{
		int t = Delete();
		cout << "Delete:"<< t << endl << "heap: ";
		for(int i =1; i <= size;i++)
			cout << heap[i] <<" ";
		cout << endl;
	}

}
