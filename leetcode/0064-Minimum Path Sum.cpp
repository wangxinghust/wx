#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		//第一行
		for (int i = 1; i < grid[0].size(); i++)
		{
			grid[0][i] += grid[0][i - 1];
		}
		//第一列
		for (int i = 1; i < grid.size(); i++) {
			grid[i][0] += grid[i - 1][0];
		}

		for (int i = 1; i < grid.size(); i++) {
			for (int j = 1; j < grid[0].size(); j++) {
				grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
			}
		}

		return grid[grid.size() - 1][grid[0].size() - 1];
	}
};