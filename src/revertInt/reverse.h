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

// updated on 2018.11.16
int reverse(int x) {
	long result = 0;
	int temp = abs(x);
	while (temp > 0) {
		result = result * 10 + temp % 10;
		temp = temp / 10;
	}
	if (result > INT_MAX || result < INT_MIN) return 0;
	return x > 0 ? result : -result;
}
