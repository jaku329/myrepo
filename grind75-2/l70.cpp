// 70. Climbing Stairs

// recursive w/o memorization => TLE
int climbStairs(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairs(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  
  int dp1 = 1;
  int dp2 = 2;
  
  while (n > 2) {
    dp1 = dp1 + dp2;
	swap(dp1, dp2);
    n--;
  }
  return dp2;
}
