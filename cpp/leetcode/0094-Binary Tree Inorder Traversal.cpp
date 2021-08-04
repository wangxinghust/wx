#include <vector>
using namespace std;

// Definition for a binary tree node
#include <cstddef>
#include <stack>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//二叉树 中序遍历 非递归
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode* p = root;
		vector<int> res;
		while (p || !s.empty()) {
			while (p) {
				//res.push_back(p->val); // preorder traversal
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				p = s.top();
				res.push_back(p->val); // inorder traversal
				s.pop();
				p = p->right;
			}
		}
		return res;
	}
};