#include <deque>
using namespace std;

// Definition for a binary tree
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

class Solutioin {
public:
	//µÝ¹éÐ´·¨
	//Runtime: 4 ms, faster than 93.81% of C++ online submissions for Symmetric Tree.
	//Memory Usage : 14.8 MB, less than 62.28 % of C++ online submissions for Symmetric Tree.
	bool isSymmetricLeaf(TreeNode* l, TreeNode* r) {
		if (!l && !r) return true;
		if (l && r && l->val == r->val) return isSymmetricLeaf(l->left, r->right) && isSymmetricLeaf(l->right, r->left);
		return false;
	}
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetricLeaf(root->left, root->right);
	}

	//leetcode Approach 2: Iterative
	bool isSymmetric2(TreeNode* root) {
		deque<TreeNode*> q;
		q.push_back(root);
		q.push_back(root);
		while (!q.empty()) {
			TreeNode* t1 = q.front();
			q.pop_front();
			TreeNode* t2 = q.front();
			q.pop_front();
			if (!t1 && !t2) continue;
			if (!t1 || !t2) return false;
			if (t1->val != t2->val) return false;
			q.push_back(t1->left);
			q.push_back(t2->right);
			q.push_back(t1->right);
			q.push_back(t2->left);
		}
		return true;
	}
};