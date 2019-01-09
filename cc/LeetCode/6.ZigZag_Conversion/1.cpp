class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> zigZag(numRows);
        bool isDescending = false;
        int i = 0;
        for(auto & c: s)
        {
            zigZag[i] += c;
            if(i == 0 || i == numRows - 1)
                isDescending = !isDescending;
            isDescending ? i++ : i--;
        }
        for(int i = 1; i < numRows; i++)
            zigZag[0] += zigZag[i];
        return zigZag[0];
    }
};