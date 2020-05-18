class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec(n);
        for (int i = 1; i <= n; i++) {
            if (i % 3 && i % 5) vec[i - 1] = to_string(i);
            if (i % 3 == 0) vec[i - 1] += "Fizz";
            if (i % 5 == 0) vec[i - 1] += "Buzz";
        }
        return vec;
    }
};