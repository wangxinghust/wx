#include <vector>
using namespace std;
// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// Runtime: 12 ms, faster than 86.01% of C++ online submissions for Path Sum II.
// Memory Usage : 19.7 MB, less than 92.11 % of C++ online submissions for Path Sum II.
class Solution {
	void recursion(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& res) {
		if (!node) return;
		if (!node->left && !node->right && node->val == sum) {
			path.push_back(node->val);
			res.push_back(path);
			path.pop_back();
			return;
		}
		/*if (!node->left) {
			path.push_back(node->val);
			recursion(node->right,sum-node->val,path,res);
			path.pop_back();
			return;
		}
		if (!node->right) {
			path.push_back(node->val);
			recursion(node->left, sum - node->val, path, res);
			path.pop_back();
			return;
		}*/
		path.push_back(node->val);
		recursion(node->left, sum - node->val, path, res);
		recursion(node->right, sum - node->val, path, res);
		path.pop_back();
	}
public:
	vector<vector<int>> pathSum(TreeNode* root,int sum) {
		vector<vector<int>> res;
		vector<int> path;
		recursion(root, sum, path, res);
		return res;
	}
};