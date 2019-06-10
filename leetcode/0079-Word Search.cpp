#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	//Runtime: 32 ms, faster than 74.43% of C++ online submissions for Word Search.
	//Memory Usage : 11 MB, less than 71.41 % of C++ online submissions for Word Search.
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty()) return word.empty();
		if (word.empty()) return true;
		vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0] && recursion(board, flag, word, 0, i, j)) return true;
			}
		}
		return false;
	}
	bool recursion(vector<vector<char>>& board, vector<vector<bool>>& flag, string& word, int index, int x, int y) {
		if (x<0 || x>board.size() - 1 || y<0 || y>board[0].size() - 1 || flag[x][y] || board[x][y] != word[index]) return false;
		if (index == word.length() - 1 && board[x][y] == word[index]) return true;
		else if (index < word.length() - 1 && board[x][y] == word[index]) {
			flag[x][y] = true;
			if (recursion(board, flag, word, index + 1, x + 1, y) ||
				recursion(board, flag, word, index + 1, x - 1, y) ||
				recursion(board, flag, word, index + 1, x, y + 1) ||
				recursion(board, flag, word, index + 1, x, y - 1)) {
				return true;
			}
			flag[x][y] = false;
			//return false;
		}
		return false;
	}
};

int main(int argc, char* argv[]) {
	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";
	Solution s;
	bool b = s.exist(board, word3);
	return 0;
}