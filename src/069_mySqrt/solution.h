// 使用二分法寻找平方根
class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        else if (x < 4) return 1;
        else if (x == 4) return 2;

        int left = 0, right = x / 2 + 1;

        long mid = (left + right) / 2;
        while (left <= right) {
            if (mid * mid > x) right = mid - 1;
            else if (mid * mid < x) left = mid + 1;
            else return mid;
            mid = (left + right) / 2;
        }
        return left - 1;
    }
};
