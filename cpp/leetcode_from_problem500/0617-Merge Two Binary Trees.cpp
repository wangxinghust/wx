#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Runtime: 40 ms, faster than 58.57% of C++ online submissions for Merge Two Binary Trees.
// Memory Usage : 13.5 MB, less than 94.44 % of C++ online submissions for Merge Two Binary Trees.
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2) {
			return NULL;
		}
		else if (t1 && t2) {
			t1->val += t2->val;
			t1->left = mergeTrees(t1->left, t2->left);
			t1->right = mergeTrees(t1->right, t2->right);
			return t1;
		}
		else if (t1 && !t2) {
			return t1;
		}
		else {
			t1 = t2;
			return t1;
		}
	}
};