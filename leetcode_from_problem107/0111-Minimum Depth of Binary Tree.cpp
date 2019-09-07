#include <algorithm>
using namespace std;

// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

// Runtime: 8 ms, faster than 95.74% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage : 20.1 MB, less than 42.86 % of C++ online submissions for Minimum Depth of Binary Tree.
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};