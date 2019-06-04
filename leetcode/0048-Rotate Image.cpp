#include <vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		int circle = matrix.size() % 2 == 1 ? len / 2 + 1 : len / 2;
		for (int i = 0; i < circle; ++i) {
			for (int j = i; j < len - 1 - i; ++j) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[len - 1 - j][i];
				matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
				matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
				matrix[j][len - 1 - i] = tmp;
			}
		}
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int> > matrix = { {5,1,9,11} ,{2,4,8,10}, {13,3,6,7}, {15,14,12,16} };
//	Solution s;
//	s.rotate(matrix);
//	return 0;
//}