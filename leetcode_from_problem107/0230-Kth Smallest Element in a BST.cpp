#include <stack>
using namespace std;
// definition for a binary tree node.
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 利用中序遍历
// Runtime: 12 ms, faster than 99.68% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage : 21.5 MB, less than 64.65 % of C++ online submissions for Kth Smallest Element in a BST.
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> s;
		TreeNode* p = root;
		int step = 0;
		while (p != nullptr||!s.empty()) {
			while (p != nullptr) {
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				p = s.top();
				if (++step == k) {
					return p->val;
				}
				s.pop();
				p = p->right;
			}
		}
		return -1;
	}
};

//What if the BST is modified(insert / delete operations) oftenand
//you need to find the kth smallest frequently ?
//How would you optimize the kthSmallest routine ?

//combine an indexing structure(we could keep BST here) with a double linked list.