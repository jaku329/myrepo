// 8. String to Integer (atoi)

class MyAtoi {
public:
  int myAtoi(string s) {
    int i = 0;
    bool positive = true;
    while (i < s.size() && (s[i] <= '0' || s[i] > '9')) {
      if (s[i] == '-') positive = false;
      i++;
    }
    if (i >= s.size()) return 0;

    long val = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
      val *= 10;
      val += (long)(s[i] - '0');
      if (positive && val > INT_MAX) return INT_MAX;
      else if (val < INT_MIN) return INT_MIN;
      i++;
    }
    return (int) (positive ? val : 0 - val);
  }
};
