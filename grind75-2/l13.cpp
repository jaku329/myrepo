// 13. Roman to Integer

// O(n);O(1)
int romanInteger(string s) {
  int result = 0;
  int i = s.size() - 1;
  unordered_map<char, int> umap;
  umap['I'] = 1;
  umap['V'] = 5;
  umap['X'] = 10;
  umap['L'] = 50;
  umap['C'] = 100;
  umap['D'] = 500;
  umap['M'] = 1000;

  int prev = 0;
  while (i >= 0) {
    int cur = umap[s[i]];
    if (cur >= prev) result += cur;
    else result -= cur;
    prev = cur;
    i--;
  }

  return result;
}
