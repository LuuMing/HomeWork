class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	if(nums.empty())	return 0;
    auto j = nums.begin() + 1;
	for(auto i = nums.begin(); j!=nums.end();)
	{
		if(*i == *j)
		{
            j = nums.erase(j);
		}
        else
        {
            i++;
            j++;
        }
	}     
    return nums.size();
    }
};
