#include <queue>
using namespace std;

// definition for a node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() {}
	Node(int _val, Node* _left, Node* _right, Node* _next) :val(_val), left(_left), right(_right), next(_next) {}
};

// Runtime: 404 ms, faster than 54.00% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage : 67 MB, less than 30.44 % of C++ online submissions for Populating Next Right Pointers in Each Node II.
// 层历的同时，维持一个size，当size为0时，说明一层遍历结束，将该节点next值置为nullptr，并同时重置size
class Solution {
public:
	Node* connect(Node* root) {
		// 边界条件，避免将 nullpr 添加到队列里
		if (!root) return nullptr;
		// 声明队列，用于层历
		queue<Node*> q;
		// 添加节点到队列里
		q.push(root);
		// 维持一个size变量，用来区分每一层
		int size = q.size();
		while (!q.empty()) {
			Node* tmp = q.front();
			q.pop();
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
			// 取出队列变量的同时，递减size
			--size;
			if (!size||q.empty()) { // 貌似不用判断 q.empty()
				tmp->next = nullptr; // 也不用重新给 next 赋值为 nullptr，默认值即是 nullptr
				size = q.size();
			}
			else {
				tmp->next = q.front();
			}
		}
		return root;
	}
};