// 338. Counting Bits

vector<int> countBits(int n) {
  vector<int> result;
  result.push_back(0);
  if (n == 0) return result;
  result.push_back(1);
  if (n == 1) return result;
  int i = 2;
  int j = 1;
  int k = 1; // represent 2^0, 2^1, 2^2, ...
  while (i <= n) {
    if (j == k) {
	  result.push_back(1);
	  k = k << 1;
	  j = 1;
	}
	else { // j < k
	  result.push_back(1 + result[j]);
	  j++;
	}
    i++;
  }
  return result;
}
