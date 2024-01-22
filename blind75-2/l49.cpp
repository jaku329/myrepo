// 49. Group Anagrams

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> result;
  unordered_map<string, vector<string>> umap;
  for (auto str : strs) {
    string key = str;
    sort(key.begin(), key.end());
    umap[key].push_back(str);
  }
  for (auto kv : umap) {
    result.push_back(kv->second);
  }
  return result;
}
