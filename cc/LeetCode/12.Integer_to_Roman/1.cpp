class Solution {
public:
    string intToRoman(int num) {
  	string roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int weight[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	int i = 12;
	string result;
	while(num && i >= 0)
	{
		if(num / weight[i] != 0)
		{
			result += roman[i];
			num -= weight[i];
		}
		else
		{
			i--;
		}
	}
	return result;   	 
    }
};
