// 50. Pow(x, n)

// recursive: TLE
double subPow(double x, int n) {
  if (n == 1) return x;
  if (n & 0x1)
    return subPow(x, n >> 1) * subPow(x, n >> 1) * x;
  return subPow(x, n >> 1) * subPow(x, n >> 1);
}

double myPow(double x, int n) {
  if (n == 0) return 1;
  double result = subPow(x, abs(n));
  if (n < 0)
    return 1 / result;
  return result;
}

// recrusive + memorize: MLE
double subPow(double x, int n, vector<double>& dp) {
  if (dp[n - 1] == 0) {
    dp[n - 1] = subPow(x, n >> 1, dp) * subPow(x, n >> 1, dp);
    if (n & 0x1)
      dp[n - 1] *= x;
  }
  return dp[n - 1];
}

double myPow(double x, int n) {
  if (x == 0) return 0;
  else if (n == 0) return 1;
  vector<double> dp(abs(n), 0);
  dp[0] = x;
  double result = subPow(x, abs(n), dp);
  if (n < 0)
    return 1 / result;
  return result;
}


// recrusive + memorize with hash map
double subPow(double x, long n, unordered_map<long, double>& dp) {
  if (dp.count(n) == 0) {
    dp[n] = subPow(x, n >> 1, dp) * subPow(x, n >> 1, dp);
    if (n & 0x1)
      dp[n] *= x;
  }
  return dp[n];
}

double myPow(double x, int n) {
  if (x == 0) return 0;
  else if (x == 1) return 1; // from 5ms to 0ms
  else if (n == 0) return 1;
  unordered_map<long, double> dp;
  dp[0] = 1;
  dp[1] = x;
  double result = subPow(x, abs(n), dp);
  if (n < 0)
    return 1 / result;
  return result;
}

