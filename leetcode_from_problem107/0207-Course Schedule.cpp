#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// leetcode by jianchao-li BFS
// Runtime: 24 ms, faster than 65.56% of C++ online submissions for Course Schedule.
// Memory Usage : 13.8 MB, less than 39.65 % of C++ online submissions for Course Schedule.
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		graph g = buildGraph(numCourses, prerequisites);
		vector<int> degrees = computeIndegrees(g);
		for (int i = 0; i < numCourses; i++) {
			int j = 0;

			// try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph
			// 也就是找不到一门无先修课的课时，必然成环
			for (; j < numCourses; j++) {
				if (!degrees[j]) {
					break;
				}
			}
			if (j == numCourses) {
				return false;
			}

			// set its indegree to be - 1 to prevent from visiting it again
			// 也就是避免再次找入度为0的点时，重新遍历该点
			degrees[j]--;

			// reduce the indegrees of its neighbors by 1
			// 即找入度为0的点，也就是无先修课程的，将其后修课程的入度降1，相当于在graph中去除该点
			for (int v : g[j]) {
				degrees[v]--;
			}
		}
		return true;
	}
private:
	typedef vector<vector<int>> graph;

	// 建立邻接表，可以考虑建立逆邻接表
	graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
		graph g(numCourses);
		for (auto p : prerequisites) {
			g[p[1]].push_back(p[0]);
		}
		return g;
	}

	// 计算入度
	vector<int> computeIndegrees(graph& g) {
		vector<int> degrees(g.size(), 0);
		for (auto adj : g) {
			for (int v : adj) {
				degrees[v]++;
			}
		}
		return degrees;
	}
};

// DFS
// in each visit, we start from a node and keep visiting its neighbors, 
// if at a time we return to a visited node, there is a cycle.
// Otherwise, start again from another unvisited node and repeat this process. 
// We use todo and done for nodes to visit and visited nodes.
// Runtime: 24 ms, faster than 65.56% of C++ online submissions for Course Schedule.
// Memory Usage : 16.6 MB, less than 14.95 % of C++ online submissions for Course Schedule.
class Solution2 {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		graph g = buildGraph(numCourses, prerequisites);
		vector<bool> todo(numCourses, false), done(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			// 如果未访问，并且成环，则返回false
			if (!done[i] && !acyclic(g, todo, done, i)) {
				return false;
			}
		}
		return true;
	}
private:
	typedef vector<vector<int>> graph;

	// 建立邻接表
	graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
		graph g(numCourses);
		for (auto p : prerequisites) {
			g[p[1]].push_back(p[0]);
		}
		return g;
	}

	// 判断是否是非循环
	bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
		// 如果有环，则会访问todo过的点
		if (todo[node]) {
			return false;
		}
		// 如果遇到done过点，说明后续不成环，返回true
		if (done[node]) {
			return true;
		}
		todo[node] = done[node] = true;
		// 对该点连接的个点判断是否不成环，即DFS
		for (int v : g[node]) {
			if (!acyclic(g, todo, done, v)) {
				// 成环，则层层退出递归
				return false;
			}
		}
		// 出度为0，则todo设置为false，返回true
		todo[node] = false;
		return true;
	}
};

// leetcode by linz36: BFS
// Runtime: 20 ms, faster than 89.71% of C++ online submissions for Course Schedule.
// Memory Usage : 12.7 MB, less than 52.15 % of C++ online submissions for Course Schedule.
class Solution3 {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// 声明邻接表
		vector<vector<int>> adj(numCourses, vector<int>());
		// 声明入度
		vector<int> degree(numCourses, 0);
		// 建立邻接表，计算入度
		for (auto& p : prerequisites) {
			adj[p[1]].push_back(p[0]);
			degree[p[0]]++;
		}
		queue<int> q;
		// 遇到入度为0的点，丢到队列，即找入度为0的点
		for (int i = 0; i < numCourses; i++)
			if (degree[i] == 0) q.push(i);
		// 遍历入度为0的点
		while (!q.empty()) {
			int curr = q.front(); q.pop(); numCourses--;
			// 遍历邻接的点，如果--后入度为0，则再丢到队列用于下次遍历
			for (auto next : adj[curr])
				if (--degree[next] == 0) q.push(next);
		}
		// 判定是否每个点都恰好入度为0过 有循环的点，入度无法降为0
		return numCourses == 0;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> prerequisites = { {1,0},{2,1},{3,2},{4,3},{2,0} };
//	bool b = Solution2().canFinish(5, prerequisites);
//	return 0;
//}