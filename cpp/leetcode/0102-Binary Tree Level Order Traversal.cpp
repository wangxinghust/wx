#include <vector>
using namespace std;

// Definition for a binary tree.
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		vector<TreeNode*> level;
		level.push_back(root);
		while (!level.empty()) {
			vector<TreeNode*> tmp;
			vector<int> val;
			for (auto t : level) {
				val.push_back(t->val);
				if (t->left) {
					tmp.push_back(t->left);
				}
				if (t->right) {
					tmp.push_back(t->right);
				}
			}
			level.assign(tmp.begin(), tmp.end());
			res.push_back(val);
		}
		return res;
	}
};

//int main(int argc, char* argv[]) {
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	TreeNode* tmp = root->right;
//	tmp->left = new TreeNode(15);
//	tmp->right = new TreeNode(7);
//
//	vector<vector<int>> ans = Solution().levelOrder(root);
//	return 0;
//}