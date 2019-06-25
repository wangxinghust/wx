#include <deque>
using namespace std;

//Definition for a binary tree node.
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
	//递归
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
	//Memory Usage : 10 MB, less than 36.32 % of C++ online submissions for Same Tree.
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if ((p && q) && p->val == q->val) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else return false;
	}

	//leetcode approach 1: Recursion
	bool isSameTree1(TreeNode* p, TreeNode* q) {
		// p and q are both null
		if (!p && !q) return true;
		// one of p and q is null
		if (!p || !q) return false;
		if (p->val != q->val) return false;
		return isSameTree1(p->right, q->right) && isSameTree1(p->left, q->left);
	}

	// leetcode approach 2: Iteration
	//Runtime: 4 ms, faster than 84.41% of C++ online submissions for Same Tree.
	//Memory Usage : 10 MB, less than 41.15 % of C++ online submissions for Same Tree.
	bool check(TreeNode* p, TreeNode* q) {
		// p and q are null
		if (!p && !q) return true;
		// one of p and q is null
		if (!p || !q) return false;
		if (p->val != q->val) return false;
		return true;
	}
	bool isSameTree2(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (!check(p, q)) return false;

		//init deques
		deque<TreeNode*> deqP;
		deque<TreeNode*> deqQ;
		deqP.push_back(p);
		deqQ.push_back(q);
		while (!deqP.empty()) {
			p = deqP.front();
			deqP.pop_front();
			q = deqQ.front();
			deqQ.pop_front();

			if (!check(p, q)) return false;
			if (p) {
				if (!check(p->left, q->left)) return false;
				//分别将p,q的左子结点添加到deque中
				deqP.push_back(p->left);
				deqQ.push_back(q->left);
				if (!check(p->right, q->right)) return false;
				//同上
				deqP.push_back(p->right);
				deqQ.push_back(q->right);
			}
		}
		return true;
	}
};

//int main(int argc, char* argv[]) {
//	/*TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);*/
//
//	TreeNode* p = new TreeNode(1);
//	p->right = new TreeNode(2);
//	TreeNode* tmp = p->right;
//	tmp->left = new TreeNode(3);
//
//	TreeNode* q = new TreeNode(1);
//	q->right = new TreeNode(2);
//	tmp = q->right;
//	tmp->right = new TreeNode(3);
//
//	bool b = Solution().isSameTree2(p, q);
//	return 0;
//}