// 383. Ransom Note

bool canConstruct(string ransomNote, string magazine) {
  vector<int> cSet(26, 0);
  for (int i = 0; i < magazine.size(); ++i)
    cSet[magazine[i] - 'a']++;
  for (int i = 0; i < ransomNote.size(); ++i)
    if (cSet[ransomNote[i] - 'a'] == 0)
	  return false;
	else
	  cSet[ransomNote[i] - 'a']--;
  return true;
}
