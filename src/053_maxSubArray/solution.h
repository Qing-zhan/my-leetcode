// O(n)
// f(n) denotes if you use a(n), the max sum you can obatin
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int prev = nums[0];
        int next = 0;
        int max_sum = prev;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (prev <= 0) next = nums[i];
            else next = prev + nums[i];
            max_sum = max(max_sum, next);
            prev = next;
        }
        
        return max_sum;
    }
};
