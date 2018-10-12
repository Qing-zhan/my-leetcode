class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        if (nums.size() < 3) return result; 
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    ++j;
                    continue;
                } 
                if (k < nums.size() - 1 && nums[k] == nums[k+1]) {
                    --k;
                    continue;
                }
                
                if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    result.push_back(std::vector<int>({nums[i], nums[j], nums[k]}));
                    --k;
                    ++j;
                }
            }
        }
        return result;
    }
};
