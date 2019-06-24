#include <queue>
#include <string>
#include <iostream>
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
		if (root == NULL) return true;
		if (depth(root->left) > depth(root->right) + 1 || depth(root->right) > depth(root->left) + 1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
	int depth(TreeNode* root) {
		if (root == NULL) return 0;
		return max(depth(root->left) + 1, depth(root->right) + 1);
	}

	// leetcode by yuzhoujr
	// 引入-1
	bool isBalanced2(TreeNode* root) {
		int height = getHeight(root);
		return height != -1;
	}
	int getHeight(TreeNode* root) {
		if (!root) return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		if (left == -1 || right == -1) return -1;
		if (abs(left - right) > 1) return -1;
		return max(left, right) + 1;
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

		if (++i < nums.size()) {
			if (nums[i] != "null") {
				node->left = new TreeNode(stoi(nums[i]));
				nodeQueue.push(node->left);
			}
			else {
				node->left = nullptr;
			}

		}
		if (++i < nums.size() && nums[i] != "null") {
			if (nums[i] != "null") {
				node->right = new TreeNode(stoi(nums[i]));
				nodeQueue.push(node->right);
			}
			else {
				node->right = nullptr;
			}
		}
	}
	return root;
}

//int main(int argc, char* argv[]) {
//	vector<vector<string>> testcase;
//	vector<string> nums = { "3","9","20","null","null","15","7" };
//	testcase.push_back(nums);
//	vector<string> nums2 = { "1","2","2","3","3","null","null","4","4" };
//	testcase.push_back(nums2);
//	vector<string> nums3 = { "1","null","2","null","3" };
//	testcase.push_back(nums3);
//	vector<string> nums4 = { "1","2","2","3","3","3","3","4","4","4","4","4","4","null","null","5","5" };
//	testcase.push_back(nums4);
//	for (auto v : testcase) {
//		TreeNode* root = CreateTree(v);
//		bool b = Solution().isBalanced(root);
//		cout << b << endl;
//	}
//	return 0;
//}