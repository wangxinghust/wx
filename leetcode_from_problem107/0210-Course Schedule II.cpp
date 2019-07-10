#include <vector>
#include <queue>
using namespace std;

// ����0207-Course Schedule, �����Ϊ0�ĵ�
// Runtime: 12 ms, faster than 99.95% of C++ online submissions for Course Schedule II.
// Memory Usage : 13.2 MB, less than 41.52 % of C++ online submissions for Course Schedule II.
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		// �����ڽӱ�
		vector<vector<int>> adj(numCourses, vector<int>());
		// �������
		vector<int> degree(numCourses, 0);
		// �����ڽӱ��������
		for (auto& p : prerequisites) {
			adj[p[1]].push_back(p[0]);
			++degree[p[0]];
		}
		queue<int> q;
		vector<int> ret;
		// �������Ϊ0�ĵ㶪������
		for (int i = 0; i < numCourses; i++) {
			if (degree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int curr = q.front();
			// ����ǰ�㶪�����������
			ret.push_back(curr);
			q.pop();
			--numCourses;
			for (auto next : adj[curr]) {
				if (--degree[next] == 0) q.push(next);
			}
		}
		// ����޷����ɣ����ؿ�
		if (numCourses != 0) return vector<int>();
		return ret;
	}
};