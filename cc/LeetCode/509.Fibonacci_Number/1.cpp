class Solution {
public:
    unordered_map<int, int> m = {{0,0},{1,1}};
    int fib(int N) {
        if( m.count(N) )
            return m[N];
        else{
            m[N] = fib(N - 1) + fib(N - 2);
            return m[N];
        }
    }
};
