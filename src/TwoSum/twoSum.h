#include<iostream>
#include<vector>
using namespace std;
//
class Solution {
public:
	vector<int> twoSum (vector<int&> nums, int target) {
		vector<int> result(2, 0);
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				result[0] = i;
				result[1] = j;
			}
		}
		return result;
	}
};

// testcases
// 1. nums = [2, 7, 11, 15], target = 9, return: [0,1]
// 2. nums = [3, 2, 4], targert = 6, return: [1,2]
