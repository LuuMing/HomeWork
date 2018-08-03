#include <iostream>
using namespace std;
int main() {
int sum[4];int hong=1;
for(int po=1;po<=4;po++){

	for(int dong=1;dong<=4;dong++){	if(po==dong){continue;}
	
		for(int tai=1;tai<=4;tai++){
	        if(tai==dong||tai==po){continue;}
			hong=10-po-dong-tai;
				sum[0]=(dong==1)+(hong==4)+(po==3);
				sum[1]=(hong==1)+(dong==4)+(po==2)+(tai==3);
			    sum[2]=(hong==4)+(dong==3);
			    sum[3]=(po==1)+(tai==4)+(hong==2)+(dong==3);
			    if(sum[0]==1&&sum[1]==1&&sum[2]==1&&sum[3]==1){
			    	cout<<po<<endl<<dong<<endl<<tai<<endl<<hong<<endl;}
			    
			}
		
		}
	
	}

	
	




    return 0;
}
