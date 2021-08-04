// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

// Runtime: 8 ms, faster than 96.39% of C++ online submissions for Path Sum.
// Memory Usage : 19.9 MB, less than 89.58 % of C++ online submissions for Path Sum.
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left && !root->right && root->val == sum) return true;
		if (!root->left) return hasPathSum(root->right, sum - root->val);
		if (!root->right) return hasPathSum(root->left, sum - root->val);
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};