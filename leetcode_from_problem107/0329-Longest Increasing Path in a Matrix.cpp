#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// leetcode by hanm & zzg_zzm
// Runtime: 296 ms, faster than 7.65% of C++ online submissions for Longest Increasing Path in a Matrix.
// Memory Usage : 83.3 MB, less than 7.23 % of C++ online submissions for Longest Increasing Path in a Matrix.
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (!rows) return 0;
		int cols = matrix[0].size();

		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		std::function<int(int, int)> dfs = [&](int x, int y) {
			if (dp[x][y]) return dp[x][y];
			vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
			for (auto& dir : dirs) {
				int xx = x + dir[0], yy = y + dir[1];
				if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
				if (matrix[xx][yy] <= matrix[x][y]) continue;
				dp[x][y] = std::max(dp[x][y], dfs(xx, yy));
			}
			return ++dp[x][y];
		};

		int ret = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				ret = std::max(ret, dfs(i, j));
			}
		}

		return ret;
	}
};

// leetcode by fkamzn
// dfs，求每个点出发的最长长度，且可复用，在求另一个点时，遍历到此点，不必再往下遍历，直接加上去即可
// Runtime: 44 ms, faster than 66.09% of C++ online submissions for Longest Increasing Path in a Matrix.
// Memory Usage : 13.8 MB, less than 45.76 % of C++ online submissions for Longest Increasing Path in a Matrix.
class Solution2 {
	int DFS(vector<vector<int>>& matrix, int y, int x, int val, vector<vector<int>>& hash)
	{
		if (y < 0 || y >= matrix.size() || x < 0 || x >= matrix[0].size())
			return 0;
		if (matrix[y][x] > val)
		{
			if (hash[y][x] != 0) return hash[y][x]; //if this path has been searched
			int a = DFS(matrix, y, x + 1, matrix[y][x], hash) + 1;
			int b = DFS(matrix, y, x - 1, matrix[y][x], hash) + 1;
			int c = DFS(matrix, y + 1, x, matrix[y][x], hash) + 1;
			int d = DFS(matrix, y - 1, x, matrix[y][x], hash) + 1;
			hash[y][x] = max(a, max(b, max(c, d)));
			return hash[y][x];
		}
		return 0;
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return 0;
		int Max = 0;
		vector<int> tem(matrix[0].size(), 0);
		vector<vector<int>> hash(matrix.size(), tem);
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);
		return Max;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> matrix = { {9,9,4},{6,6,8},{2,1,1} };
//	int ret = Solution().longestIncreasingPath(matrix);
//	return 0;
//}