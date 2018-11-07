class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int s1 = a.size();
        int s2 = b.size();
        string result(max(s1,s2),'0');
        for(int i = s1-1,j = s2 - 1, idx = max(s1,s2)-1; i >= 0 || j >= 0 ; i--,j--,idx--)
        {
            int sum = ((i >= 0 )? a[i]-'0' : 0)+  ((j>= 0)?b[j] -'0': 0)+ carry;
            carry = sum / 2;
            result[idx] = sum % 2 + '0';
        }
        if(carry)
        {
            result.insert(result.begin(),'1');
        }
        return result;
    }
};