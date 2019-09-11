#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// definition for a node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {}
	Node(int _val, vector<Node*> _neighbors) :val(_val), neighbors(_neighbors) {}
};

// leetcode by jianchao-li
// bfs
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return nullptr;
		Node* copy = new Node(node->val, {});
		copies[node] = copy;
		queue<Node*> todo;
		todo.push(node);
		while (!todo.empty()) {
			Node* cur = todo.front();
			todo.pop();
			for (Node* neighbor : cur->neighbors) {
				if (copies.find(neighbor) == copies.end()) {
					copies[neighbor] = new Node(neighbor->val, {});
					todo.push(neighbor);
				}
				copies[cur]->neighbors.push_back(copies[neighbor]);
			}
		}
		return copy;
	}
private:
	unordered_map<Node*, Node*> copies;
};

class Solution2 {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return nullptr;
		if (copies.find(node) == copies.end()) {
			copies[node] = new Node(node->val, {});
			for (Node* neighbor : node->neighbors) {
				copies[node]->neighbors.push_back(cloneGraph(neighbor));
			}
		}
		return copies[node];
	}
private:
	unordered_map<Node*, Node*> copies;
};