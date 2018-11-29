// f(n) = f(n-1) + f(n-2)
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1;
        int f2 = 2;
        if (n == 0) return 0;
        else if (n == 1) return f1;
        else if (n == 2) return f2;
        
        int fn = 0;
        for (int i = 3; i <= n; ++i) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};
