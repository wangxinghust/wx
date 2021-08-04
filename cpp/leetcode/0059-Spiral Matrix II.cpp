#include <vector>
using namespace std;
class Solution {
public:
	//根据0054稍作修改
	//Runtime: 4 ms, faster than 93.69% of C++ online submissions for Spiral Matrix II.
	//Memory Usage : 9 MB, less than 45.65 % of C++ online submissions for Spiral Matrix II.
	vector<vector<int>> generateMatrix(int n) {		
		vector<vector<int>> matrix(n, vector<int>(n));

		int startRow = 0, startCol = 0, endRow = matrix.size() - 1, endCol = matrix[0].size() - 1;

		int num = 1;
		while (startRow <= endRow && startCol <= endCol) {
			for (int i = startCol; i <= endCol; ++i) {
				matrix[startRow][i] = num++;
			}
			++startRow;
			if (startRow <= endRow) {
				for (int i = startRow; i <= endRow; ++i) {
					matrix[i][endCol] = num++;
				}
			}
			--endCol;
			if (startRow <= endRow && startCol <= endCol) {
				for (int i = endCol; i >= startCol; --i) {
					matrix[endRow][i] = num++;
				}
			}
			--endRow;
			if (startRow <= endRow && startCol <= endCol) {
				for (int i = endRow; i >= startRow; --i) {
					matrix[i][startCol] = num++;
				}
			}
			++startCol;
		}

		return matrix;
	}
};