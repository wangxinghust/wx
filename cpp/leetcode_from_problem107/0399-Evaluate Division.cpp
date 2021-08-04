#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// leetcode by Mad_air
// Union-find algorithm 并查集
// 并查集是一种树型的数据结构，一种常用的策略是为每个集合选定一个固定的元素，称为代表（或者代表元）
// 有一个联合-查找算法定义了两个操作用于此数据结构
// 1.Find 返回元素所属集合的代表，确定元素属于哪一个子集合，可以用来确定两个元素是否属于同一子集
// 2.Union 将两个子集合并成同一个集合，将一个集合的代表指向另一个集合的代表
class Solution {
	struct Node {
		Node* parent;
		double value = 0.0;// 表示当前节点/parent的值，我觉得定为1.0更好，因为自己除自己为1.0
		Node() { parent = this; }
	};
	Node* findParent(Node* node) {
		if (node->parent == node)
			return node;
		node->parent = findParent(node->parent);
		return node->parent;
	}
	void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
		Node* parent1 = findParent(node1), * parent2 = findParent(node2);
		double ratio = node2->value * num / node1->value;// 计算出来的是parent1/parent2
		for (auto it = map.begin(); it != map.end(); ++it) {
			if (findParent(it->second) == parent1)
				it->second->value *= ratio;
		}// 经过循环后，父节点为parent1的都乘上了 parent1/parent2，也就是父节点都将指向 parent2
		parent1->parent = parent2;// 合并两个集合
	}
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, Node*> map;
		vector<double> res;
		for (int i = 0; i < equations.size(); i++) {
			string s1 = equations[i][0], s2 = equations[i][1];
			if (map.count(s1) == 0 && map.count(s2) == 0) {
				map[s1] = new Node();
				map[s2] = new Node();
				map[s1]->value = values[i];
				map[s2]->value = 1.0;
				map[s1]->parent = map[s2];
			}
			else if (map.count(s1) == 0) {
				map[s1] = new Node();
				map[s1]->value = map[s2]->value * values[i];
				map[s1]->parent = map[s2];
			}
			else if (map.count(s2) == 0) {
				map[s2] = new Node();
				map[s2]->value = map[s1]->value / values[i];
				map[s2]->parent = map[s1];
			}
			else {
				unionNodes(map[s1], map[s2], values[i], map);
			}
		}

		for (auto query : queries) {
			// map中不存在 query[0] || query[1] , 或者两者不在一个集合
			if (map.count(query[0]) == 0 || map.count(query[1]) == 0 || findParent(map[query[0]]) != findParent(map[query[1]])) {
				res.push_back(-1.0);
			}
			else {
				res.push_back(map[query[0]]->value / map[query[1]]->value);
			}
		}
		return res;
	}
};

//int main() {
//	vector<vector<string>> equations = { {"a","b"},{"b","c"} };
//	vector<double> values = { 2.0,3.0 };
//	vector<vector<string>> queries = { {"a","c"},{"b","a"} ,{"a","e"},{"a","a"},{"x","x"} };
//	vector<double> res = Solution().calcEquation(equations, values, queries);
//	cout << fixed << setprecision(1);
//	for (auto d : res) {
//		cout << d << " ";
//	}
//	cout << endl;
//	return 0;
//}