// 
// f(n) = 1  if n <= 1023
//        f(n-1) + f(n-1024) n >= 1024

int f(int n) {
	if (n <= 1023) return 1;
	std::vector<int> result(1024, 1);
	for (int i = 1024; i <= n; ++i) {
		result[i % 1024] = result[(i-1)%1024] + result[(i-1024)%1024];
	}
	return result[n % 1024];
}

// If not use recursive method, then mediate value of f(n) must be 
// stored to calculate next value;
