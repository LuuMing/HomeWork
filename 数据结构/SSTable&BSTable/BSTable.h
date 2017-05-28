#ifndef SSTABLE_H
#define SSTABLE_H
#endif 
#include<iostream>
using namespace std;
template <class ElemType>
class BSTable : public SSTable<ElemType>    //由SSTable派生出BSTable  
{
	public:
		BSTable ( int n): SSTable<ElemType> (n)
		{
			cout<<"开始排序"<<endl;                //在构造函数内完成排序 
			int i, j;
			ElemType temp;
		    for (j = 0; j < this->length - 1; j++)
		        for (i = 0; i < this->length - 1 - j; i++)
		        {
		            if(this->elem[i] > this->elem[i + 1])
		            {
		                temp = this->elem[i];
		                this->elem[i] = this->elem[i + 1];
		                this->elem[i + 1] = temp;
		            }
		        }
			cout<<"排序完毕,当前表内元素为:";
			for (int i = 0; i < this->length; i++)
			{
				cout << this->elem[i]<<' ';
			}
			cout<<endl;
		};
		int Search_Bia( auto key )   //折半查找，使用auto类型来接收不同类型参数,返回元素在表中的下标，0为起始.
		{
			int low = 0;
			int high = this->length; 
			while(low <= high)
	        {
	            int mid = (low+high) / 2;
	            if( this->elem [mid] > key )
	                high = mid-1;
	            else if ( this->elem[mid] < key )
	            	low = mid+1;
	            else
				{
					cout << "元素已找到。位置为";
					cout << mid <<endl; 
					return mid;
				}
	                
	        }
	        cout<<"元素未找到。"<<endl;
    		return -1;
		}
	
}; 
