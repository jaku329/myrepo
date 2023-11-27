// https://leetcode.com/problems/valid-sudoku/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
  vector<unordered_set<char>> subBoards(9, unordered_set<char>());
  vector<unordered_set<int>> colMap(9, unordered_set<int>());

  for (int i = 0; i < board.size(); ++i) {
    int subBoard;
    
    unordered_set<char> rowSet;
    for (int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == '.') continue;

      subBoard = j / 3 + (i / 3) * 3;
      if (subBoards[subBoard].count(board[i][j]) > 0) {
        return false;
      }
      else {
        subBoards[subBoard].insert(board[i][j]);

        if (rowSet.count(board[i][j]) > 0) {
          return false;
        }
        else rowSet.insert(board[i][j]);

        int digit = board[i][j] - '0' - 1;
        if (colMap[digit].count(j) > 0) {
          return false;
        }
        colMap[digit].insert(j);
      }
    }
  }
  return true;
}

int main() {
  vector<vector<char>> board = {
/*
{'5','3','.','.','7','.','.','.','.'},
 {'6','.','.','1','9','5','.','.','.'},
 {'.','9','8','.','.','.','.','6','.'},
 {'8','.','.','.','6','.','.','.','3'},
 {'4','.','.','8','.','3','.','.','1'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','6','.','.','.','.','2','8','.'},
 {'.','.','.','4','1','9','.','.','5'},
 {'.','.','.','.','8','.','.','7','9'}
 };
*/
{'.','1','.','5','2','.','.','.','.'},
{'.','.','.','.','.','6','4','3','.'},
{'.','.','.','.','.','.','.','.','.'},
{'5','.','.','.','.','.','9','.','.'},
{'.','.','.','.','.','.','.','5','.'},
{'.','.','.','5','.','.','.','.','.'},
{'9','.','.','.','.','3','.','.','.'},
{'.','.','6','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'}
};
  cout << isValidSudoku(board);
  return 0;
}

