class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while (x > 9 || x < -9) {
            result = result * 10 + x % 10;
            x = x / 10;
        }
        result = result*10 + x;
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};

// testcases:
// 1. x = 123 return:321
// 2. x = -123 return:-321
// 3. x = 1534236469 return:0
// 4. x = -2147483648 return:0