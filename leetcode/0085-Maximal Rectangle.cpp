#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//类似0084，将每一行的最大值转换为右边界减左边界乘上当前高，也就是说将二维矩阵转为三个二维矩阵
	//Runtime: 20 ms, faster than 96.12% of C++ online submissions for Maximal Rectangle.
	//Memory Usage : 11.6 MB, less than 37.48 % of C++ online submissions for Maximal Rectangle.
	int maximalRectangle(vector<vector<char>>& matrix) {
		int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
		vector<int> heights(cols, 0);
		// init
		for (int j = 0; j < cols; j++) {
			if (matrix[0][j] == '0') {
				heights[j] = 0;
			}
			else {
				heights[j]++;
			}
		}
		int maxAreaInRow = largestRectangleArea(heights);

		// compare
		for (int i = 1; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == '0') {
					heights[j] = 0;
				}
				else {
					heights[j]++;
				}
			}
			maxAreaInRow = max(maxAreaInRow, largestRectangleArea(heights));
		}
		return maxAreaInRow;


	}

	//0084
	int largestRectangleArea(vector<int>& heights) {
		//validate input
		if (heights.size() == 0) return 0;

		//init
		int n = heights.size();
		vector<int> left(n);
		vector<int> right(n);
		int result = 0;

		//build left
		left[0] = 0;
		for (int i = 1; i < n; i++) {
			int currentLeft = i - 1;
			//不断向左遍历，直至某个值小于heights[i]
			while (currentLeft >= 0 && heights[currentLeft] >= heights[i]) {
				currentLeft = left[currentLeft] - 1;
			}
			left[i] = currentLeft + 1;
		}

		//build right
		right[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			int currentRight = i + 1;
			//同上
			while (currentRight < n && heights[currentRight] >= heights[i]) {
				currentRight = right[currentRight] + 1;
			}
			right[i] = currentRight - 1;
		}

		//compare height
		for (int i = 0; i < n; i++) {
			result = max(result, (right[i] - left[i] + 1) * heights[i]);
		}

		return result;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<char>> matrix = { {'1','0','1','0','0'} ,  {'1','0','1','1','1'},	{'1','1','1','1','1' },	{'1','0','0','1','0'} };
//	Solution s;
//	int  ans = s.maximalRectangle(matrix);
//	return 0;
//}