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
			// Ҳ�����Ҳ���һ�������޿εĿ�ʱ����Ȼ�ɻ�
			for (; j < numCourses; j++) {
				if (!degrees[j]) {
					break;
				}
			}
			if (j == numCourses) {
				return false;
			}

			// set its indegree to be - 1 to prevent from visiting it again
			// Ҳ���Ǳ����ٴ������Ϊ0�ĵ�ʱ�����±����õ�
			degrees[j]--;

			// reduce the indegrees of its neighbors by 1
			// �������Ϊ0�ĵ㣬Ҳ���������޿γ̵ģ�������޿γ̵���Ƚ�1���൱����graph��ȥ���õ�
			for (int v : g[j]) {
				degrees[v]--;
			}
		}
		return true;
	}
private:
	typedef vector<vector<int>> graph;

	// �����ڽӱ����Կ��ǽ������ڽӱ�
	graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
		graph g(numCourses);
		for (auto p : prerequisites) {
			g[p[1]].push_back(p[0]);
		}
		return g;
	}

	// �������
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
			// ���δ���ʣ����ҳɻ����򷵻�false
			if (!done[i] && !acyclic(g, todo, done, i)) {
				return false;
			}
		}
		return true;
	}
private:
	typedef vector<vector<int>> graph;

	// �����ڽӱ�
	graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
		graph g(numCourses);
		for (auto p : prerequisites) {
			g[p[1]].push_back(p[0]);
		}
		return g;
	}

	// �ж��Ƿ��Ƿ�ѭ��
	bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
		// ����л���������todo���ĵ�
		if (todo[node]) {
			return false;
		}
		// �������done���㣬˵���������ɻ�������true
		if (done[node]) {
			return true;
		}
		todo[node] = done[node] = true;
		// �Ըõ����ӵĸ����ж��Ƿ񲻳ɻ�����DFS
		for (int v : g[node]) {
			if (!acyclic(g, todo, done, v)) {
				// �ɻ��������˳��ݹ�
				return false;
			}
		}
		// ����Ϊ0����todo����Ϊfalse������true
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
		// �����ڽӱ�
		vector<vector<int>> adj(numCourses, vector<int>());
		// �������
		vector<int> degree(numCourses, 0);
		// �����ڽӱ��������
		for (auto& p : prerequisites) {
			adj[p[1]].push_back(p[0]);
			degree[p[0]]++;
		}
		queue<int> q;
		// �������Ϊ0�ĵ㣬�������У��������Ϊ0�ĵ�
		for (int i = 0; i < numCourses; i++)
			if (degree[i] == 0) q.push(i);
		// �������Ϊ0�ĵ�
		while (!q.empty()) {
			int curr = q.front(); q.pop(); numCourses--;
			// �����ڽӵĵ㣬���--�����Ϊ0�����ٶ������������´α���
			for (auto next : adj[curr])
				if (--degree[next] == 0) q.push(next);
		}
		// �ж��Ƿ�ÿ���㶼ǡ�����Ϊ0�� ��ѭ���ĵ㣬����޷���Ϊ0
		return numCourses == 0;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> prerequisites = { {1,0},{2,1},{3,2},{4,3},{2,0} };
//	bool b = Solution2().canFinish(5, prerequisites);
//	return 0;
//}