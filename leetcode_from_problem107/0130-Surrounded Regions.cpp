#include <vector>
using namespace std;

// Runtime: 24 ms, faster than 98.65% of C++ online submissions for Surrounded Regions.
// Memory Usage : 14.4 MB, less than 38.56 % of C++ online submissions for Surrounded Regions.
class Solution {
private:
	void connect(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, int x, int y) {
		if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y] || board[x][y] == 'X') return;
		visited[x][y] = true;
		connect(board, visited, row, col, x - 1, y);
		connect(board, visited, row, col, x + 1, y);
		connect(board, visited, row, col, x, y - 1);
		connect(board, visited, row, col, x, y + 1);
	}
public:
	void solve(vector<vector<char>>& board) {
		int row = board.size();

		int col = row > 0 ? board[0].size() : 0;
		if (!row || !col) return;
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		// 从上下左右边界的'O'进入回溯
		for (int j = 0; j < col; j++) {
			if (board[0][j] == 'O') connect(board, visited, row, col, 0, j);
			if (board[row - 1][j] == 'O') connect(board, visited, row, col, row - 1, j);
		}
		for (int i = 1; i < row - 1; i++) {
			if (board[i][0] == 'O') connect(board, visited, row, col, i, 0);
			if (board[i][col - 1] == 'O') connect(board, visited, row, col, i, col - 1);
		}

		// 遍历board矩阵，修改
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (!visited[i][j]) board[i][j] = 'X';
			}
		}
	}
};

// 降低空间占用思路之一：1.将可连通的'O'标记为'V'，2.将剩下的'O'置'X'，3.将'V'恢复为'O'

//int main(int argc, char* argv[]) {
//	vector<vector<char>> board = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
//	Solution().solve(board);
//
//	return 0;
//}