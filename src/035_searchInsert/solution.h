class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
// O(n)
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] == target) return i;
//             else if (nums[i] > target) {
//                 return i;
//             }
//         }
        
//         return nums.size();
        
        // O(log n) ,using bisect partition
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else return mid;
        }
        return left;
    }
};
