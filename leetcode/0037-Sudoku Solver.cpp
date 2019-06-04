#include <vector>
using namespace std;
class Solution {
public:
	//leetcode by nilath2
	void solveSudoku(vector<vector<char>>& board) {
		solveSudoku(board, 0, 0);
	}
	//�����У����У��˷���������valֵ
	bool check(vector<vector<char>>& board, int i, int j, char val)
	{
		for (int h = 0; h < 9; h++)
		{
			if (board[i][h] == val) return false; /* check row */
			if (board[h][j] == val) return false; /* check col */
			//h/3��h%3�õĺ��
			if (board[i - i % 3 + h / 3][j - j % 3 + h % 3] == val) return false; /* check cube */
		}

		return true;
	}
	bool solveSudoku(vector<vector<char>>& board, int i, int j)
	{
		//i��9����ɱ���
		if (i == 9) return true;
		//j��9����ɲ���������һ��
		if (j == 9) return solveSudoku(board, i + 1, 0);
		//�������֣�������һ��
		if (board[i][j] != '.') return solveSudoku(board, i, j + 1);

		//��1��9����������
		for (char c = '1'; c <= '9'; c++)
		{
			if (check(board, i, j, c))
			{
				//����
				board[i][j] = c;
				//�ж���һ���ַ� ���Ϊ���򷵻�
				if (solveSudoku(board, i, j + 1)) return true;
				//���Ϊ�٣���Ҫ�ָ�Ϊ�ո�״̬
				board[i][j] = '.';
			}
		}

		//���1��9��Щ�ַ������ܷ��룬�򷵻�false
		return false;
	}
};


//int main(int argc, char* argv[]) {
//	vector<vector<char> > board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},{'6', '.', '.', '1', '9', '5', '.', '.', '.'},{'.', '9', '8', '.', '.', '.', '.', '6', '.'},{'8', '.', '.', '.', '6', '.', '.', '.', '3'},{'4', '.', '.', '8', '.', '3', '.', '.', '1'},{'7', '.', '.', '.', '2', '.', '.', '.', '6'},{'.', '6', '.', '.', '.', '.', '2', '8', '.'},{'.', '.', '.', '4', '1', '9', '.', '.', '5'},{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
//	Solution s;
//	s.solveSudoku(board);
//	return 0;
//}