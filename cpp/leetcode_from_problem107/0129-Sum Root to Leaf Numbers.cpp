#include <unordered_map>
#include <queue>
using namespace std;
// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		// 边界限定
		if (!root) return 0;

		// 如果允许修改TreeNode->val，可直接修改
		unordered_map<TreeNode*, int> treeNum;
		queue<TreeNode*> q;
		q.push(root);
		treeNum[root] = root->val;
		int result = 0;
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (!t->left && !t->right) {
				result += treeNum[t];
			}
			if (t->left) {
				q.push(t->left);
				treeNum[t->left] = treeNum[t] * 10 + t->left->val;
			}
			if (t->right) {
				q.push(t->right);
				treeNum[t->right] = treeNum[t] * 10 + t->right->val;
			}
		}
		return result;
	}
};