#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// leetcode by Mad_air
// Union-find algorithm ���鼯
// ���鼯��һ�����͵����ݽṹ��һ�ֳ��õĲ�����Ϊÿ������ѡ��һ���̶���Ԫ�أ���Ϊ�������ߴ���Ԫ��
// ��һ������-�����㷨�����������������ڴ����ݽṹ
// 1.Find ����Ԫ���������ϵĴ���ȷ��Ԫ��������һ���Ӽ��ϣ���������ȷ������Ԫ���Ƿ�����ͬһ�Ӽ�
// 2.Union �������Ӽ��ϲ���ͬһ�����ϣ���һ�����ϵĴ���ָ����һ�����ϵĴ���
class Solution {
	struct Node {
		Node* parent;
		double value = 0.0;// ��ʾ��ǰ�ڵ�/parent��ֵ���Ҿ��ö�Ϊ1.0���ã���Ϊ�Լ����Լ�Ϊ1.0
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
		double ratio = node2->value * num / node1->value;// �����������parent1/parent2
		for (auto it = map.begin(); it != map.end(); ++it) {
			if (findParent(it->second) == parent1)
				it->second->value *= ratio;
		}// ����ѭ���󣬸��ڵ�Ϊparent1�Ķ������� parent1/parent2��Ҳ���Ǹ��ڵ㶼��ָ�� parent2
		parent1->parent = parent2;// �ϲ���������
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
			// map�в����� query[0] || query[1] , �������߲���һ������
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