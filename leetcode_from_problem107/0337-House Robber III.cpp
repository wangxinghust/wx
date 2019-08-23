#include <queue>
#include <unordered_map>
using namespace std;
// definition for a tree node.
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

// 递归算法，有许多重复计算的，可以考虑剪枝算法，标记已算好的，然后剪去重复的计算
// Runtime: 1472 ms, faster than 5.00% of C++ online submissions for House Robber III.
// Memory Usage : 20.7 MB, less than 88.89 % of C++ online submissions for House Robber III.
class Solution {
	int recurse(TreeNode* node) {
		if (!node) return 0;
		if (!node->left && !node->right) return node->val;
		int leftMoney = 0, rightMoney = 0;
		if (node->left) leftMoney = recurse(node->left->left) + recurse(node->left->right);
		if (node->right) rightMoney = recurse(node->right->left) + recurse(node->right->right);
		return max((node->left ? recurse(node->left) : 0) + (node->right ? recurse(node->right) : 0), node->val + leftMoney + rightMoney);
	}
public:
	int rob(TreeNode* root) {
		return recurse(root);
	}
};

// leetcode by sansyrox
// 用map去存已经遍历过的值，关键在最后的return，同时赋值，也就是在退出深层递归的同时，改变map的值
class Solution2 {
	unordered_map<TreeNode*, int> um;
public:
	int rob(TreeNode* root) {
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return root->val;

		/*if (um.find(root) != um.end()) 
			return um[root];*/
		// 改后能降低Runtime
		if (um.count(root) != 0) 
			return um[root];

		int curr = root->val;
		if (root->left)
			curr += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			curr += rob(root->right->right) + rob(root->right->left);
		
		return um[root] = max(curr, rob(root->left) + rob(root->right));
	}
};