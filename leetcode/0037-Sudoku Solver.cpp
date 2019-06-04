#include <vector>
using namespace std;
class Solution {
public:
	//leetcode by nilath2
	void solveSudoku(vector<vector<char>>& board) {
		solveSudoku(board, 0, 0);
	}
	//检查此行，此列，此方框里有无val值
	bool check(vector<vector<char>>& board, int i, int j, char val)
	{
		for (int h = 0; h < 9; h++)
		{
			if (board[i][h] == val) return false; /* check row */
			if (board[h][j] == val) return false; /* check col */
			//h/3和h%3用的很妙啊
			if (board[i - i % 3 + h / 3][j - j % 3 + h % 3] == val) return false; /* check cube */
		}

		return true;
	}
	bool solveSudoku(vector<vector<char>>& board, int i, int j)
	{
		//i到9，完成遍历
		if (i == 9) return true;
		//j到9，完成层历，到下一层
		if (j == 9) return solveSudoku(board, i + 1, 0);
		//已有数字，移至下一个
		if (board[i][j] != '.') return solveSudoku(board, i, j + 1);

		//从1到9，挨个尝试
		for (char c = '1'; c <= '9'; c++)
		{
			if (check(board, i, j, c))
			{
				//填入
				board[i][j] = c;
				//判断下一个字符 如果为真则返回
				if (solveSudoku(board, i, j + 1)) return true;
				//如果为假，需要恢复为空格状态
				board[i][j] = '.';
			}
		}

		//如果1到9这些字符都不能放入，则返回false
		return false;
	}
};


//int main(int argc, char* argv[]) {
//	vector<vector<char> > board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},{'6', '.', '.', '1', '9', '5', '.', '.', '.'},{'.', '9', '8', '.', '.', '.', '.', '6', '.'},{'8', '.', '.', '.', '6', '.', '.', '.', '3'},{'4', '.', '.', '8', '.', '3', '.', '.', '1'},{'7', '.', '.', '.', '2', '.', '.', '.', '6'},{'.', '6', '.', '.', '.', '.', '2', '8', '.'},{'.', '.', '.', '4', '1', '9', '.', '.', '5'},{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
//	Solution s;
//	s.solveSudoku(board);
//	return 0;
//}