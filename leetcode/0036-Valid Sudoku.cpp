#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			set<char> chRow, chColumn;
			for (int j = 0; j < 9; ++j) {
				if (chRow.find(board[i][j]) != chRow.end()) return false;
				else {
					if (board[i][j] != '.') {
						chRow.insert(board[i][j]);
					}
				}
				if (chColumn.find(board[j][i]) != chColumn.end()) return false;
				else {
					if (board[j][i] != '.') {
						chColumn.insert(board[j][i]);
					}
				}
			}
		}
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				set<char> chBox;
				for (int m = 0; m < 3; ++m) {
					for (int n = 0; n < 3; ++n) {
						if (chBox.find(board[i + m][j + n]) != chBox.end()) return false;
						else {
							if (board[i+m][j+n] != '.') {
								chBox.insert(board[i + m][j + n]);
							}
						}
					}
				}
			}
		}
		return true;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<char> > board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},{'6', '.', '.', '1', '9', '5', '.', '.', '.'},{'.', '9', '8', '.', '.', '.', '.', '6', '.'},{'8', '.', '.', '.', '6', '.', '.', '.', '3'},{'4', '.', '.', '8', '.', '3', '.', '.', '1'},{'7', '.', '.', '.', '2', '.', '.', '.', '6'},{'.', '6', '.', '.', '.', '.', '2', '8', '.'},{'.', '.', '.', '4', '1', '9', '.', '.', '5'},{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
//	Solution s;
//	bool b = s.isValidSudoku(board);
//	return 0;
//}