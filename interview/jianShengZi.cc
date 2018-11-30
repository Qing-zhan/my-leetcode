// Problem description
// Given a string with length n, cut it into m pieces, where n > 1 and m > 1, calculate the maximum multiplier of all the pieces by their length. 
// e.g. n = 3, m = 2, then one piece with length 1  and other piece with length 2, the multiplier is 2.

// 1. 对于长度为n的绳子，假设第一刀切在j，此时得到的最大乘积为 j * f[n-j], 遍历 j from 1 to n-1，选择最大值即可
int maxMul(int n) {
  std::vector<int> f(n+1, 0);
  f[1] = 1;
  f[2] = 1;

  for (int i = 3; i <= n; ++i) {
    int max = 0;
    for (int j = 1; j < n; ++j) {
      int temp = j * f[n-j];
      max = temp > max ? temp : max;
    }
    f[i] = max;
  }

  return f[n];
}

// 2. 假设有一刀切在了 j 位置，那么最大乘积必定为前半部分的最大值乘以后半部分的最大值，即 f[n] = f[j] * f[n-j], 遍历 j from 1 to n/2 即可；
int maxMulPro(int n) {
  if (n == 2) return 1;
  
  std::vector<int> f(n+1, 0);
  f[1] = 1;
  f[2] = 2;
  
  for (int i = 3; i <= n; ++i) {
    int max = 0;
    for (int j = 1; j <= n/2; ++j) {
      int temp = f[j] * f[n-j];
      max = temp > max ? temp : max;
    }
    f[i] = max;
  }

  return f[n];
}
