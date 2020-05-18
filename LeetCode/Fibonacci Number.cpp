class Solution {
   public:
    int fib(int N) {
        int a = 0, b = 1, c;
        while (N--) {
            c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};