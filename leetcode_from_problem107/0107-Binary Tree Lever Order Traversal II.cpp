#include <vector>
#include <queue>
using namespace std;

//definition for a binary tree node.
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
	//add reverse
	//Runtime: 8 ms, faster than 85.29% of C++ online submissions for Binary Tree Level Order Traversal II.
	//Memory Usage : 13.6 MB, less than 96.66 % of C++ online submissions for Binary Tree Level Order Traversal II.
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		int n = q.size();
		while (n) {
			vector<int> data;
			for (int i = 0; i < n; i++) {
				TreeNode* tmp = q.front();
				q.pop();
				data.push_back(tmp->val);
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
			res.push_back(data);
			n = q.size();
		}
		reverse(res.begin(), res.end());
		return res;
	}

	//calculate depth of the binary tree
	//leetcode by phu1ku
	//Runtime: 8 ms, faster than 85.29% of C++ online submissions for Binary Tree Level Order Traversal II.
	//Memory Usage : 14.6 MB, less than 30.35 % of C++ online submissions for Binary Tree Level Order Traversal II.
	int depth(TreeNode* root) {
		if (!root) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}
	void levelOrder(vector<vector<int>>& ans, TreeNode* node, int level) {
		if (!node) return;
		ans[level].push_back(node->val);
		levelOrder(ans, node->left, level - 1);
		levelOrder(ans, node->right, level - 1);
	}
	vector<vector<int>> levelOrderBottom2(TreeNode* root) {
		int d = depth(root);
		vector<vector<int>> ans(d, vector<int>{});
		levelOrder(ans, root, d - 1);
		return ans;
	}
};