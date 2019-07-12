#include <vector>
using namespace std;

// Runtime: 72 ms, faster than 61.95% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage : 12.8 MB, less than 76.57 % of C++ online submissions for Search a 2D Matrix II.
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size(), col = row == 0 ? 0 : matrix[0].size();
		int x = row - 1, y = 0;
		while (x >= 0 && y < col) {
			// 向上收缩，待优化：求x的值可以用二分查找来找第一个小于等于targe的
			while (x >= 0 && matrix[x][y] > target) {
				--x;
			}
			// 向右收缩, 加上x>=0，防止x越界
			while (x >= 0 && y < col && matrix[x][y] < target) {
				++y;
			}
			// 判断是否越界，并同时判断是否值相等
			if (x >= 0 && y < col && matrix[x][y] == target) return true;
		}
		return false;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<vector<int>> matrix = { {1,4,7,11,15}, {2,5,8,12,19} ,{3,6,9,16,22} ,{10,13,14,17,24} ,{18,21,23,26,30} };
//	vector<vector<int>> matrix = { {-5} };
//	bool b = Solution().searchMatrix(matrix, -10);
//	return 0;
//}