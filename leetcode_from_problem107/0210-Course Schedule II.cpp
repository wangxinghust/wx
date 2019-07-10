#include <vector>
#include <queue>
using namespace std;

// 类似0207-Course Schedule, 找入度为0的点
// Runtime: 12 ms, faster than 99.95% of C++ online submissions for Course Schedule II.
// Memory Usage : 13.2 MB, less than 41.52 % of C++ online submissions for Course Schedule II.
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		// 声明邻接表
		vector<vector<int>> adj(numCourses, vector<int>());
		// 声明入度
		vector<int> degree(numCourses, 0);
		// 建立邻接表，计算入度
		for (auto& p : prerequisites) {
			adj[p[1]].push_back(p[0]);
			++degree[p[0]];
		}
		queue<int> q;
		vector<int> ret;
		// 遇到入度为0的点丢到队列
		for (int i = 0; i < numCourses; i++) {
			if (degree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int curr = q.front();
			// 将当前点丢到结果数组里
			ret.push_back(curr);
			q.pop();
			--numCourses;
			for (auto next : adj[curr]) {
				if (--degree[next] == 0) q.push(next);
			}
		}
		// 如果无法构成，返回空
		if (numCourses != 0) return vector<int>();
		return ret;
	}
};