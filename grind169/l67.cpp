// 67. Add Binary

string addBinary(string a, string b) {
  string s;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  char carrige = 0;
  int i = 0;
  while (i < a.size() || i < b.size()) {
    char bit = 0;
    if (i < a.size())
      bit += a[i] & 0x1; 
    if (i < b.size())
      bit += b[i] & 0x1;
    bit += carrige;
    carrige = bit >> 1;
    s += (bit & 0x1) + '0';
    i++;
  }
  if (carrige)
    s += '1';
  reverse(s.begin(), s.end());
  return s;
}
