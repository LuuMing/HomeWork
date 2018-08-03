#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int count(string s)
{
	int times = 0;
	for(int i = 0; i < s.size(); i++)                      //循环考虑每一位
	{
		if(s.at(i) == '0')  //当前位==0，则该位出现1的情况由更高位决定，=更高位数字*当前位数
		{
			times += pow(10,s.size()-i-1)*stoi(s.substr(0,i).empty()?"0":s.substr(0,i));
		}
		else if(s.at(i) == '1')//当前位==1，则该位出现1的情况受更高位以及低位的影响
		{		       //=(更高位数字*当前位数)+(低位数字+1)
			times += pow(10,s.size()-i-1)*stoi(s.substr(0,i).empty()?"0":s.substr(0,i));
			times += stoi(s.substr(i+1,s.size()).empty()?"0":s.substr(i+1,s.size())) + 1;
		}
		else                   //如果当前位>1，则该位出现1的情况由更高位决定，
		{		       //=(更高位数字+1)*当前位数
			times += (stoi(s.substr(0,i).empty()?"0":s.substr(0,i))+1) * pow(10,s.size()-i-1);
		}
	}
	return times;
}
int main()
{
	string num;
	cin >> num;
	cout << count(num);
} 
