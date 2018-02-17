#include<queue>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
class Time
{
	int HH;
	int MM;
public:
	Time(int H,int M)
	{

		HH = H; 
		MM = M;
	}
	void click()
	{
		MM++;
		if(MM == 60)
		{
			MM = 0;
			HH++;
		}
	}
	string get_time()
	{
		char buffer[6];
		sprintf(buffer,"%02d:%02d",HH,MM);
		string r = buffer;
		return r;
	}
	bool operator==(const Time&t2)
	{
		return (this->HH == t2.HH && this->MM == t2.MM);
	}
	void plus(int t)
	{
		HH += (MM+t)/60;
		MM = (MM + t)%60;
	}
};
struct customer            
{
	int num;                 //for recorder
	int time;                //process time
	bool visit = false;      //for after 17:00
};
int main()
{
	int N,M,K,Q;
	cin >> N >> M >> K >>Q;
	vector<queue<customer>> windows(N);           //in the line
	queue<customer> outline;                      
	vector<string> recorder(K);                   //store the leave time
	vector<customer> customers(K);
	vector<int> query(Q);
	for(int i = 0; i < K;i++)                     //init state, loop all the customer.
	{
		cin >> customers[i].time;
		customers[i].num = i;
		if(i < N*M)
			windows[i%N].push(customers[i]);
		else
			outline.push(customers[i]);
	}
	for(int i = 0; i < Q;i++)
	{
		cin >> query[i];
	}
	Time T(8,0);
	Time E(17,0);
	while(!(T==E))                               //simulate every time
	{
		T.click();                           
		for(auto &window:windows)            //handle front of the queue
		{
			if(!window.empty())
			{
				window.front().time--;
				window.front().visit =true;
			}
		}
		for(int i = 0; i < N;i++)           //If complete: 1.record 2.customer from outline into inline area.
		{
			if(!windows[i].empty())
			{
				if(windows[i].front().time==0)
				{
					recorder[windows[i].front().num] = T.get_time();
					windows[i].pop();
					if(!outline.empty())
					{
						windows[i].push(outline.front());
						outline.pop();
					}
				}
			}
		}
	}
	for(int i = 0; i < N;i++)                 //If out of service, but still handling.
	{					  //record final time.
		Time end(17,0);
		if(!windows[i].empty())
		{
			if(windows[i].front().visit)
			{
				end.plus(windows[i].front().time);
				recorder[windows[i].front().num] = end.get_time();
				windows[i].pop();
			}
		}
	}
	stringstream ss;
	for(int i = 0; i < Q;i++)               //if no information, sorry.
	{
		if(recorder[query[i]-1] == "")
		{
			ss <<"Sorry"<<endl;
		}
		else
			ss << recorder[query[i]-1] <<endl;
	}	
	string out =ss.str();
	out.erase(out.end()-1);
	cout <<out;
}
