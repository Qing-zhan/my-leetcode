int removeDuplicates(std::vector<int>& nums) {
	if (nums.size() == 0) return 0;

	int index = 0, curr = 0;

	while (curr < nums.size()) {
		if (nums[curr] > nums[index]) {
			nums[++index] = nums[curr];
		}
		++curr;
	}
	return ++index;
}
