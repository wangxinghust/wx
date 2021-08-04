#include <cstddef>
#include <queue>
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Runtime: 4 ms, faster than 59.01% of C++ online submissions for Invert Binary Tree.
// Memory Usage : 9.1 MB, less than 96.36 % of C++ online submissions for Invert Binary Tree.
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root) {
			TreeNode* tmp = root->left;
			root->left = invertTree(root->right);
			root->right = invertTree(tmp);
		}
		return root;
	}
};

// 非递归写法
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
// Memory Usage : 9.1 MB, less than 94.55 % of C++ online submissions for Invert Binary Tree.
class Solution2 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;
		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* target = q.front(); q.pop();
			TreeNode* tmp = NULL;
			if (target->left) {
				q.push(target->left);
				tmp = target->left;				
			}
			target->left = target->right;
			if (target->right) {
				q.push(target->right);
			}
			target->right = tmp;
		}
		return root;
	}
};