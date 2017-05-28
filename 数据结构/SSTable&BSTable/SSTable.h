
#include<iostream>
using namespace std; 

template <class ElemType>   // 模板类 
class SSTable
{
	public:
		ElemType * elem;
		int length;
		void print()
		{
			cout << "表中的元素有:";
			for( int i = 0 ; i < length ; i++)
				cout << elem [i] <<' ';
			cout<<endl;
			
		};
		SSTable ( int n):length(n)
		{
			elem = new 	ElemType [n];
			cout << "请输入"<<n<<"个元素:"; 
			for( int i = 0; i < length ;i++)
			{
				cin >> elem[i];
			}
			
			cout<<endl<<"输入完毕。";
		};
		virtual	~SSTable ()
		{
			delete []elem;
		}; 
		int Search_Seq( auto key  );
};

template <class ElemType>
int SSTable< ElemType >:: Search_Seq( auto key  )//使用auto类型来接收不同类型参数,返回元素在表中的下标，0为起始 
{
	for ( int i =0 ; i < length; i++)
	{
		if( elem[i] == key)
		{
			cout<< "元素已找到。位置为"; 
			cout<< i <<endl;
			return i;
		} 
	}
	cout << "元素未找到。"<<endl;
	return 0;
}

