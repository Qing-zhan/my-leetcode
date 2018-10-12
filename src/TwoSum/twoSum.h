#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        
        // 1. brutal force -- complexity: n^n
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = i + 1; j < nums.size(); ++j) {
        //         if (nums[i] + nums[j] == target) {
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }
        
        // 2. hash table -- complexity: n * log n
        std::unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(target - nums[i]) == um.end()) {
                um.insert(std::make_pair(nums[i], i));
            } else {
                result.push_back(i);
                result.push_back(um[target - nums[i]]);
            }
        }
        std::sort(result.begin(), result.end());
        
        // 3. sort the array first
        /*
        do not work, because title demands that no same digit can be 
        used more than twice.
        */
        // std::unordered_map<int, int> um;
        // for (int i = 0; i < nums.size(); ++i) {
        //     um.insert(std::make_pair(nums[i], i));
        // }
        // std::sort(nums.begin(), nums.end());
        // int p1 = 0;
        // int p2 = nums.size() - 1;
        // while (nums[p1] + nums[p2] != target) {
        //     if (nums[p1] + nums[p2] > target) {
        //         p2--;
        //     } else {
        //         p1++;
        //     }
        // }
        // result.push_back(um[nums[p1]]);
        // result.push_back(um[nums[p2]]);
        
        return result;
    }
};
