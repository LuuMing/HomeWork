#include<iostream>
using namespace std;

class Clock
{
	private:
		int hour;
		int minute;
		int second;
	public:
	    Clock(int hh, int mm, int ss):hour(hh), minute(mm), second(ss){ count ++; };
		void showTime();
		static int count;
}; 

void Clock::showTime()
{
	cout<<hour<<':'<<minute<<':'<<second<<endl;
}

int Clock:: count = 0; 

int main()
{
	Clock myClock(9, 53, 30);
	myClock.showTime();
	cout << myClock.count << endl;
	Clock anClock (9, 59, 30);
	cout << myClock.count << endl;
	cout << anClock.count << endl;
	anClock.showTime();
}
