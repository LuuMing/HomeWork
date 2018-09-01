class Solution {
public:
    int myAtoi(string str) {
        cout << INT_MAX << endl << INT_MIN << endl;
	int i = 0;
	while(str[i]==' ')i++;
	int sig = 0;
	if(str[i] == '+' || isdigit(str[i])) sig = 1;
	else if (str[i] == '-')  sig = -1;
	else
		return 0;
	if( !isdigit(str[i])) i++;
	if(!isdigit(str[i])) return 0;
	long int ans = 0;
	bool oor = false;
  	for( ;i < str.size(); i++)
	{
		if(isdigit(str[i]))
		{
            
			if(ans* 10 + (str[i] - '0') <= INT_MAX)
			{
				ans = ans* 10 + (str[i] - '0');
			}
			else
			{
				oor = true;	
				break;
			}
		}
		else
		{
			break;
		}
	}    	 
	if(oor)
	{
        if(sig == 1)
		return INT_MAX;
        else
        return INT_MIN;
	}
	else
	{
		return sig * ans;
	}
    }
};
