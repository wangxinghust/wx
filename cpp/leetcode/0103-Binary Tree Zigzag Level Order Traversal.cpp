#include <vector>
#include <stack>
#include <queue>
using namespace std;
// definition for a binary tree node.
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
public:
	//two stack
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		stack<TreeNode*> stack1, stack2;
		if (root) {
			stack1.push(root);
		}

		while (!stack1.empty() || !stack2.empty()) {
			vector<int> data;
			if (!stack1.empty()) {
				while (!stack1.empty()) {
					TreeNode* p = stack1.top();
					stack1.pop();
					data.push_back(p->val);
					if (p->left) stack2.push(p->left);
					if (p->right) stack2.push(p->right);
				}
				res.push_back(data);
			}
			else if (!stack2.empty()) {
				while (!stack2.empty()) {
					TreeNode* p = stack2.top();
					stack2.pop();
					data.push_back(p->val);					
					if (p->right) stack1.push(p->right);
					if (p->left) stack1.push(p->left);
				}
				res.push_back(data);
			}
		}
		return res;
	}

	//leetcode by StevenCooks
	//one queue and without reverse operation by using size of each level
	vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
		if (!root) return vector<vector<int>>();
		vector<vector<int>> res;

		queue<TreeNode*> nodesQueue;
		nodesQueue.push(root);
		bool leftToRight = true;
		while (!nodesQueue.empty()) {
			int size = nodesQueue.size();
			vector<int> row(size);
			for (int i = 0; i < size; i++) {
				TreeNode* node = nodesQueue.front();
				nodesQueue.pop();

				// find position to fill node's value
				int index = leftToRight ? i : size - 1 - i;
				row[index] = node->val;
				if (node->left) {
					nodesQueue.push(node->left);
				}
				if (node->right) {
					nodesQueue.push(node->right);
				}
			}
			// after this level
			leftToRight = !leftToRight;
			res.push_back(row);
		}
		return res;
	}
};