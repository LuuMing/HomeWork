class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        while(true)
        {
            if(idx >= 0)
                digits[idx]++;
            else
                digits.insert(digits.begin(),1);
            if(digits[idx] == 10)
            {
                digits[idx] = 0;
                idx--;
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};
