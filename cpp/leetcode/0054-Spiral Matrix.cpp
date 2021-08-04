#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (!matrix.size()) return ans;
		int startRow = 0, startCol = 0, endRow = matrix.size() - 1, endCol = matrix[0].size() - 1;
		while (startRow <= endRow && startCol <= endCol) {
			for (int i = startCol; i <= endCol; ++i) {
				ans.push_back(matrix[startRow][i]);
			}
			++startRow;
			if (startRow <= endRow) {
				for (int i = startRow; i <= endRow; ++i) {
					ans.push_back(matrix[i][endCol]);
				}
			}
			--endCol;
			if (startRow <= endRow && startCol <= endCol) {
				for (int i = endCol; i >= startCol; --i) {
					ans.push_back(matrix[endRow][i]);
				}
			}
			--endRow;
			if (startRow <= endRow && startCol <= endCol) {
				for (int i = endRow; i >= startRow; --i) {
					ans.push_back(matrix[i][startCol]);
				}
			}
			++startCol;
		}
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int> > matrix = { {1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12} };
//	vector<vector<int> > matrix2 = { {1,2,3},{4,5,6},{7,8,9} };
//	Solution s;
//	vector<int> ans = s.spiralOrder(matrix2);
//	return 0;
//}