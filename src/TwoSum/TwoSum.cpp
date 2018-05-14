#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
	  vector<int> result(2,0);
	  int size = nums.size();
	  for (int i = 0; i < size; i++) {
	    for (int j = i + 1; j < size; j++) {
	      if (nums[i] + nums[j] == target)
	        result[0] = i;
	        result[1] = j;
	    }
	  }
	  return result;
	}
};

int main(){
  vector<int> nums_1(2, 7, 11, 15);
  vector<int> result;
  result = twoSum(nums_1, 9);

  return 0
}
