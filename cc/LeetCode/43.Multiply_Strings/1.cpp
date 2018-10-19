class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size() ,'0'); // 生成临时结果，临时结果的长度 <= 两数位数之和
        for(int i = num1.size() - 1; i >= 0; i--)   //从个位开始计算
        {
            int add = 0;
            int n1 = num1[i] - '0';
            for(int j = num2.size() - 1; j >= 0; j--)
            {
                int mul = n1 * (num2[j] - '0');     
                int sum = add + mul  + (res[ i +j +1] - '0'); // 实质上模拟了竖式
                res[i + j +1] = sum % 10 + '0';     
                add = sum / 10;
            }
            res[i] = add + '0';                     //最后的进位不能忘记
        }
        for(int i = 0; i < res.size() ;i ++)
        {
            if( res[i] != '0' )
                return res.substr(i);
        }
        return "0";
    }
};
