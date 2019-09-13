#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int rows = grid.size(), cols = rows == 0 ? 0 : grid[0].size();
		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 2) {
					q.push({ i,j });
				}
			}
		}

		int minute = 0;

		while (!q.empty()) {
			int end = q.size();
			for (int i = 0; i < end; i++) {
				auto p = q.front();
				q.pop();
				int x = p.first, y = p.second;
				if (x - 1 >= 0 && grid[x - 1][y] == 1) {
					grid[x - 1][y] = 2;
					q.push({ x - 1,y });
				}
				if (x + 1 < rows && grid[x + 1][y] == 1) {
					grid[x + 1][y] = 2;
					q.push({ x + 1,y });
				}
				if (y - 1 >= 0 && grid[x][y - 1] == 1) {
					grid[x][y - 1] = 2;
					q.push({ x,y - 1 });
				}
				if (y + 1 < cols && grid[x][y + 1] == 1) {
					grid[x][y + 1] = 2;
					q.push({ x,y + 1 });
				}
			}
			++minute;
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return minute == 0 ? 0 : minute - 1;
	}
};