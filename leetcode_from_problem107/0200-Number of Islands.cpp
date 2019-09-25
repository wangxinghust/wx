#include <vector>
#include <queue>
using namespace std;

// Runtime: 16 ms, faster than 75.95% of C++ online submissions for Number of Islands.
// Memory Usage : 10.9 MB, less than 52.40 % of C++ online submissions for Number of Islands.
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int islands = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					islands++;
					connected(grid, i, j, visited);
				}
			}
		}
		return islands;
	}
private:
	void connected(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]) return;
		visited[x][y] = true;
		connected(grid, x + 1, y, visited);
		connected(grid, x - 1, y, visited);
		connected(grid, x, y + 1, visited);
		connected(grid, x, y - 1, visited);
	}
};

// leetcode by yfcheng: Union Find
// 建立不相交的对象集
// 将相连的元素放入同一对象集
// Find queries: are two objects in the same set?
// Union commands: replace sets containing two items by their union
// Each union command reduces by 1 the number of components
// Runtime: 36 ms, faster than 8.24% of C++ online submissions for Number of Islands.
// Memory Usage : 16.3 MB, less than 5.41 % of C++ online submissions for Number of Islands.
class Solution2 {
	vector<vector<int>> distance = { {1,0},{-1,0},{0,1},{0,-1} };
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		UnionFind* uf = new UnionFind(grid);
		int rows = grid.size();
		int cols = grid[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == '1') {
					for (auto d : distance) {
						int x = i + d[0];
						int y = j + d[1];
						if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '1') {
							int id1 = i * cols + j;
							int id2 = x * cols + y;
							uf->unionHandle(id1, id2);
						}
					}
				}
			}
		}
		return uf->count;
	}

	class UnionFind {
		vector<int> father;
		int m, n;
	public:
		int count = 0;
		UnionFind(vector<vector<char>>& grid) {
			m = grid.size();
			n = grid[0].size();
			father.assign(m * n, 0);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] == '1') {
						int id = i * n + j;
						father[id] = id;
						count++;
					}
				}
			}
		}
		void unionHandle(int node1, int node2) {
			int find1 = find(node1);
			int find2 = find(node2);
			if (find1 != find2) {
				father[find1] = find2;
				count--;
			}
		}
		int find(int node) {
			if (father[node] == node) {
				return node;
			}
			father[node] = find(father[node]);
			return father[node];
		}
	};
};

// leetcode by jianchao-li: DFS/BFS

// BFS
class Solution3 {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = { 0, 1, 0, -1, 0 };
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// Each time when I see a '1', I increment the counter and then erase all connected '1's using a queue.
				if (grid[i][j] == '1') {
					islands++;
					grid[i][j] = '0';
					queue<pair<int, int>> todo;
					todo.push({ i, j });
					while (!todo.empty()) {
						pair<int, int> p = todo.front(); 
						todo.pop();
						for (int k = 0; k < 4; k++) {
							int r = p.first + offsets[k], c = p.second + offsets[k + 1];
							if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
								grid[r][c] = '0';
								todo.push({ r, c });
							}
						}
					}
				}
			}
		}
		return islands;
	}
};

// DFS 与自己的解法类似，不同处是省去了visited矩阵，直接将相连点置0
// Runtime: 12 ms, faster than 95.07% of C++ online submissions for Number of Islands.
// Memory Usage : 10.7 MB, less than 78.93 % of C++ online submissions for Number of Islands.
class Solution4 {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					islands++;
					eraseIslands(grid, i, j);
				}
			}
		}
		return islands;
	}
private:
	void eraseIslands(vector<vector<char>>& grid, int i, int j) {
		int m = grid.size(), n = grid[0].size();
		if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
			return;
		}
		grid[i][j] = '0';
		eraseIslands(grid, i - 1, j);
		eraseIslands(grid, i + 1, j);
		eraseIslands(grid, i, j - 1);
		eraseIslands(grid, i, j + 1);
	}
};