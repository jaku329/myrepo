// 73. Set Matrix Zeroes

void setBit(vector<int>& bitArray, int pos) {
  bitArray[pos / 32] |= 1 << (pos % 32);
}

bool getBit(vector<int>& bitArray, int pos) {
  return bitArray[pos / 32] & (1 << (pos % 32));
}

void setZeros(vector<vector<int>>& matrix) {
  // 1 <= m, n length <= 200, 32bits * 7 = 224
  vector<int> mArray(7, 0);
  vector<int> nArray(7, 0);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j)
      if (matrix[i][j] == 0) {
        setBit(mArray, i);
        setBit(nArray, j);
      }
  }
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j)
      if (getBit(mArray, i) || getBit(nArray, j))
        matrix[i][j] = 0;
}
