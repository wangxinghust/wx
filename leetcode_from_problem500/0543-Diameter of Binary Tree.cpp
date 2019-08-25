#include <algorithm>
using namespace std;

// definition for a binary tree node
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// Approach #1: Depth-First Search [Accepted]
class Solution {
	int ans;
	int depth(TreeNode* node) {
		if (node == nullptr) return 0;
		int L = depth(node->left);
		int R = depth(node->right);
		ans = max(ans, L + R + 1);
		return max(L, R) + 1;
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 1;
		depth(root);
		return ans - 1; // 路径为 4 2 1 3 时，返回3，返回的是长度，而非结点数
	}
};