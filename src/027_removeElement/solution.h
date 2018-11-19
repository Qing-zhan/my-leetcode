int removeElement(std::vector<int>& nums, int val) {
	/*
	if (nums.size() == 0) return 0;
	int index = 0, curr = 0;

	for (; index < nums.size(); ++index) {
	if (nums[index] != val) continue;
	for (curr = index + 1; curr < nums.size(); ++curr) {
	if (nums[curr] == val) continue;
	break;
	}
	if (curr == nums.size()) return index;
	int temp = nums[index];
	nums[index] = nums[curr];
	nums[curr] = temp;
	}

	return index;  */

	/*
	if (nums.size() == 0) return 0;
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
	while (left < nums.size() && nums[left] != val) left++;
	while (right >= 0 && nums[right] == val) right--;
	if (left > right) break;
	int temp = nums[left];
	nums[left] = nums[right];
	nums[right] = temp;
	}
	return left;
	*/

	if (nums.size() == 0) return 0;
	int n = nums.size() - 1;
	for (int i = 0; i <= n;) {
		if (nums[i] == val) nums[i] = nums[n--];
		else ++i;
	}

	return n + 1;
}
