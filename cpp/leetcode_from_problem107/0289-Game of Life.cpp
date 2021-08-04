#include <vector>
using namespace std;
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int row = board.size();
		int col = row == 0 ? 0 : board[0].size();

		// 进行标记，2表示从1变0，-1表示从0变1
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				// 计算周边8个值的和
				int life =
					((i - 1 >= 0 && i - 1 < row && j - 1 >= 0 && j - 1 < col && board[i - 1][j - 1] > 0) ? 1 : 0) +
					((i - 1 >= 0 && i - 1 < row && j >= 0 && j < col && board[i - 1][j]>0) ? 1 : 0) +
					((i - 1 >= 0 && i - 1 < row && j + 1 >= 0 && j + 1 < col && board[i - 1][j + 1] > 0) ? 1 : 0) +
					((i >= 0 && i < row && j - 1 >= 0 && j - 1 < col && board[i][j - 1] > 0) ? 1 : 0) +
					((i >= 0 && i < row && j + 1 >= 0 && j + 1 < col && board[i][j + 1] > 0) ? 1 : 0) +
					((i + 1 >= 0 && i + 1 < row && j - 1 >= 0 && j - 1 < col && board[i + 1][j - 1] > 0) ? 1 : 0) +
					((i + 1 >= 0 && i + 1 < row && j >= 0 && j < col && board[i + 1][j] > 0) ? 1 : 0) +
					((i + 1 >= 0 && i + 1 < row && j + 1 >= 0 && j + 1 < col && board[i + 1][j + 1] > 0) ? 1 : 0);
				switch (board[i][j]) {
				case 0:
					if (life == 3) {
						--board[i][j];
					}
					break;
				case 1:
					if (life < 2 || life > 3) {
						++board[i][j];
					}
					break;
				}
			}
		}
		// 更新矩阵
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				switch (board[i][j]) {
				case -1:
					board[i][j] = 1;
					break;
				case 2:
					board[i][j] = 0;
					break;
				}
			}
		}
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
//	Solution().gameOfLife(board);
//	return 0;
//}