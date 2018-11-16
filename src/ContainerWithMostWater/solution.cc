// 1. 穷举法, time complexity:O(n^2)
int ContainerWithMostWater(std::vector<int>& height) {
	int len = height.size();
	if (len <= 1) return 0;

	int max_area = 0;
	int area = 0;

	// step from 1 to len - 1
	for (int step = 1; step < len; ++step) {
		//printf("step:%d\n", step);
		for (int i = 0; i < len - step; ++i) {
			//printf("%d -> %d  ", i, i + step);
			area = std::min(height[i], height[i + step]) * step;
			if (area > max_area) max_area = area;
		}
		//printf("\n");
	}

	return max_area;
}


/*
第一种方法使用了两层循环，遍历每一种可能的情况，时间复杂度为 O(n^2)，只击败了12%的用户
第二种方法参考了大家的做法，但是刚开始不理解为什么可以这样做：
使用左右两个索引left，right，如果height[left] < height[right]，那么 left++，否则 right--；
不理解的地方在于这样导致的结果是直接放弃了某些情况。后来发现可以这样理解：
如果 height[left] < height[right]，那么left跟中间所有的线组成的最大值，不会大于right跟中间所有的线组成的最大值，
所以，只需要去找right跟中间的最大值组合即可，而不必去找left跟中间组成的最大值；
*/

int ContainerWithMostWaterPro(std::vector<int>& height) {
	int left = 0;
	int right = height.size() - 1;
	int max_area = 0;
	while (left < right) {
		max_area = std::max(max_area, std::min(height[left], height[right]) * (right - left));
		height[left] < height[right] ? ++left : --right;
	}
	return max_area;
}
