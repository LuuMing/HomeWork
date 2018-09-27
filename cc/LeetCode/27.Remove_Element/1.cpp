class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
  	for(auto i = nums.begin(); i != nums.end();)
	{
		if(*i == val)
		{
			i = nums.erase(i);
		}	
		else
			i++;
	}    	 
        return nums.size();
    }
};
