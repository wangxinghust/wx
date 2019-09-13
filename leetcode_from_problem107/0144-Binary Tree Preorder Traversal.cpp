#include <vector>
#include <stack>
using namespace std;
// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (p || !s.empty()) {
			while (p) {
				ret.push_back(p->val);
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
		return ret;
	}
};