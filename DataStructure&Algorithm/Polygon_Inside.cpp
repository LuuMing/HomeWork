#include<iostream>
#include<vector>
using namespace std;
struct point
{
	double x;
	double y;
};
vector<point> v;
bool inside(vector<point> polygon, point target)
{
	int crossing = 0;
	for(int i = 1; i < polygon.size(); i++)
	{
		double slope = (polygon[i].y - polygon[i-1].y) / (polygon[i].x - polygon[ i-1 ].x);  // 两点之间的斜率
		bool cond1 = ( target.x >= polygon[i-1].x && target.x <= polygon[i].x);		     // target 在某边两端点之间
		bool cond2 = ( target.x >= polygon[i].x && target.x <= polygon[i-1].x);		     // target 在某边两端点之间
		bool above = (target.y < slope * ( target.x - polygon[i-1].x) + polygon[i-1].y);	// y0 < ax0+b (a = slope)即在两线的下方，因此必有一点相交
		if( (cond1 || cond2) && above) crossing++;
	}
	return (crossing % 2 != 0);									//若有奇数个点交点，在内部

}
int main()
{
	int N; cin >> N;
	for(int i = 0; i < N; i++)
	{
		point t; cin >> t.x >> t.y;
		v.push_back(t);
	}
	v.push_back(v[0]); // 方便判断，将起始点加入尾部，构成封闭图形
	point target;
	cin >> target.x >> target.y;
	cout << inside(v,target);
}
