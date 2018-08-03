#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char a[5][5];
for (int i=0;i<5;i++){
	for(int j=0;j<5;j++){cin>>a[i][j];
	}
}




int x=0,y=0;
cin>>x>>y;
 



char b[5];
for (int i=0;i<5;i++){
	b[i]=a[y][i];}
	
	for (int i=0;i<5;i++)
	{	a[y][i]=a[x][i];}
	
	for (int i=0;i<5;i++){a[x][i]=b[i];} 
	
		if(x||y>5){cout<<"error";}
	else if(x||y<0){cout<<"error";}
	else {
	for(int i=0;i<5;i++){cout<<setw(4)<<a[0][i];
	}cout<<endl;
	for(int i=0;i<5;i++){cout<<setw(4)<<a[1][i];
	}cout<<endl;
	for(int i=0;i<5;i++){cout<<setw(4)<<a[2][i];
	}cout<<endl;
	for(int i=0;i<5;i++){cout<<setw(4)<<a[3][i];
	}cout<<endl;
	for(int i=0;i<5;i++){cout<<setw(4)<<a[4][i];
	}cout<<endl;
	}



	return 0;
}
