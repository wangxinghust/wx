#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	//Runtime: 16 ms, faster than 19.16% of C++ online submissions for Search a 2D Matrix.
	//Memory Usage : 10.1 MB, less than 44.09 % of C++ online submissions for Search a 2D Matrix
	//两次二分查找
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		if (matrix[0].size() == 0) return false;
		int end = matrix[0].size() - 1;
		if (matrix[0][end] >= target) {
			return binarySearch(matrix[0], target);
		}
		int up = 0, down = matrix.size() - 1;
		while (up <= down) {
			int mid = up + (down - up) / 2;
			if (matrix[mid][end] < target) {
				up = mid + 1;
			}
			else if (matrix[mid][end] >= target) {
				down = mid - 1;
			}
		}
		if (up == matrix.size()) {
			return false;
		}
		else {
			return binarySearch(matrix[up], target);
		}
	}
	bool binarySearch(vector<int> nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);//用移位来取代/2
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				return true;
			}
		}
		return false;
	}

	//当做一个排序的一维数组来处理
	//Runtime: 8 ms, faster than 97.98% of C++ online submissions for Search a 2D Matrix.
	//Memory Usage : 9.9 MB, less than 54.99 % of C++ online submissions for Search a 2D Matrix.
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int col = matrix[0].size();
		int left = 0, right = matrix.size() * col - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			if (matrix[mid / col][mid % col] < target) {
				left = mid + 1;
			}
			else if (matrix[mid / col][mid % col] > target) {
				right = mid - 1;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> matrix = { {1} };
//	Solution s;
//	bool b = s.searchMatrix(matrix, 0);
//	cout << b << endl;
//	return 0;
//}