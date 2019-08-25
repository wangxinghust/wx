// difinition for a binary tree node
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// �����������������ͬʱ�����ۼӺ�
class Solution {
	int curSum = 0;
	void travel(TreeNode* root) {
		if (!root) return;
		if (root->right) travel(root->right);
		root->val = (curSum += root->val);
		if (root->left) travel(root->left);
	}
public:
	TreeNode* convertBST(TreeNode* root) {
		travel(root);
		return root;
	}
};