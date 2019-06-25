#include <algorithm>
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
	// recursion
	// Runtime: 932 ms, faster than 5.79% of C++ online submissions for Binary Tree Maximum Path Sum.
	// Memory Usage : 50.4 MB, less than 5.00 % of C++ online submissions for Binary Tree Maximum Path Sum.
	int maxPathSum(TreeNode* root) {
		int sum = (maxPath(root->left) > 0 ? maxPath(root->left) : 0) + root->val + (maxPath(root->right) > 0 ? maxPath(root->right) : 0);

		if (root->left && root->right) return max(max(maxPathSum(root->left), maxPathSum(root->right)), sum);
		else if (root->left) return max(maxPathSum(root->left), sum);
		else if (root->right) return max(maxPathSum(root->right), sum);
		else return sum;
	}
	int maxPath(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return root->val;
		if (root->left && root->right) {
			int tmp = max(maxPath(root->left), maxPath(root->right));
			return tmp > 0 ? tmp + root->val : root->val;
		}
		else if (root->left) {
			int tmp = maxPath(root->left);
			return tmp > 0 ? tmp + root->val : root->val;
		}
		else {
			int tmp = maxPath(root->right);
			return tmp > 0 ? tmp + root->val : root->val;
		}
	}

	// leetcode by xt2357
	// one traversal throught the tree
	// Runtime: 32 ms, faster than 76.68% of C++ online submissions for Binary Tree Maximum Path Sum.
	// Memory Usage : 24.1 MB, less than 94.18 % of C++ online submissions for Binary Tree Maximum Path Sum.
	int maxToRoot(TreeNode* root, int& re) {
		if (!root) return 0;
		// 左子树
		int l = maxToRoot(root -> left, re);
		// 右子树
		int r = maxToRoot(root->right, re);
		// l<0，舍弃左子树
		if (l < 0) l = 0;
		// 舍弃右子树
		if (r < 0) r = 0;
		// 更新re 可以用re=max(re,l + r + root->val)  Runtime: 24 ms,Memory Usage: 24.4 MB 修改后运行时间降低，空间占用增加
		if (l + r + root->val > re) re = l + r + root->val;
		return root->val += max(l, r);
	}
	int maxPathSum2(TreeNode* root) {
		int max = INT_MIN;
		maxToRoot(root, max);
		return max;
	}
};

//int main(int argc, char* argv[]) {
//	TreeNode* root = new TreeNode(2);
//	root->right = new TreeNode(-1);
//	int ans = Solution().maxPathSum(root);
//	return 0;
//}

// testcase
// [-3]