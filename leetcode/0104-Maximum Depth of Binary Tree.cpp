#include <algorithm>
#include <queue>
using namespace std;
//definitio for a binary tree.
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
	//recursion Depth-first-search
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}

	//leetcode by makuiyu Breadth-first-search
	int maxDepth2(TreeNode* root) {
		if (root == NULL)
			return 0;

		int res = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			++res;
			for (int i = 0, n = q.size(); i < n; ++i)
			{
				TreeNode* p = q.front();
				q.pop();

				if (p->left != NULL)
					q.push(p->left);
				if (p->right != NULL)
					q.push(p->right);
			}
		}

		return res;
	}
};