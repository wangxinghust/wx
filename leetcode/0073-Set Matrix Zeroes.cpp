#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	//O(m+n) space
	//Runtime: 48 ms, faster than 87.78% of C++ online submissions for Set Matrix Zeroes.
	//Memory Usage : 11.7 MB, less than 13.46 % of C++ online submissions for Set Matrix Zeroes.
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return;
		int m = matrix.size(), n = matrix[0].size();
		vector<bool> row(m, false);
		vector<bool> col(n, false);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					row[i] = true;
					col[j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (row[i] || col[j]) {
					matrix[i][j] = 0;
				}
			}
		}
		return;
	}

	//O(n)
	//Runtime: 44 ms, faster than 97.47% of C++ online submissions for Set Matrix Zeroes.
	//Memory Usage : 11.8 MB, less than 5.04 % of C++ online submissions for Set Matrix Zeroes.
	void setZeroes2(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return;
		int m = matrix.size(), n = matrix[0].size();
		set<int> col;
		for (int i = 0; i < m; i++) {
			bool isZero = false;
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					col.insert(j);
					isZero = true;
				}
			}
			if (isZero) {
				matrix[i].assign(n, 0);
			}
		}
		for (int j : col) {
			for (int i = 0; i < m; i++) {
				matrix[i][j] = 0;
			}
		}
		return;
	}

	//����set���� vector<bool>���Ǳ�set<int> Ҫʡ���ٿռ�
	//Runtime: 40 ms, faster than 99.83% of C++ online submissions for Set Matrix Zeroes.
	//Memory Usage : 11.5 MB, less than 44.43 % of C++ online submissions for Set Matrix Zeroes.
	void setZeroes3(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return;
		int m = matrix.size(), n = matrix[0].size();
		vector<bool> col(n, false);
		for (int i = 0; i < m; i++) {
			bool isZero = false;
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					col[j] = true;
					isZero = true;
				}
			}
			if (isZero) {
				matrix[i].assign(n, 0);
			}
		}
		for (int j = 0; j < n; j++) {
			if (col[j]) {
				for (int i = 0; i < m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
		return;
	}

	//leetcode Approach 1: Additional Memory Approach
	//Approach 2: Brute O(1) space.

	//Approach 3: O(1) Space, Efficient Solution
	//����ԭʼ����ֱ������ǣ�����һ�к͵�һ��������־����

	//TODO
	void setZeroes4(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		//���Ͻ�ֻ��ʾ��һ�еı�־����������һ����־������һ��
		bool isCol = false;
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) isCol = true;
			//j��1��ʼ����һ���Ƿ���Ҫ��0��isCol�����
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		//����������־�кͱ�־��
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		//������һ��
		if (matrix[0][0] == 0) {
			matrix[0].assign(n, 0);
		}
		//������һ��
		if (isCol) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}

		return;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<vector<int>> matrix = { {1,1,1},{0,1,2}};
//	s.setZeroes4(matrix);
//	return 0;
//}