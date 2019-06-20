#include <queue>
#include <string>
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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> q;
		q.push(root);
		int level = 1;
		int minLevel = 0;
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (!t->left && t->right) {
				if (!minLevel) minLevel = level;
				else if (level > minLevel + 1) return false;
			}
			else {
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			++level;
		}
		return true;
	}
};

//利用vector<int>和level order构建二叉树
TreeNode* CreateTree(vector<string>& nums) {
	if (nums.empty()) return NULL;
	TreeNode* root = new TreeNode(stoi(nums[0]));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	int i = 0;
	while (i < nums.size()) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (++i < nums.size() && nums[i] != "null") {
			node->left = new TreeNode(stoi(nums[i]));
			nodeQueue.push(node->left);
		}
		if (++i < nums.size() && nums[i] != "null") {
			node->right = new TreeNode(stoi(nums[i]));
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int main(int argc, char* argv[]) {
	vector<string> nums = { "3","9","20","null","null","15","7" };
	TreeNode* root = CreateTree(nums);
	return 0;
}