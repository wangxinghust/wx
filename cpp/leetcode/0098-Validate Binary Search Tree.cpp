// Definition for a binary tree node
#include <cstddef>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//中序遍历 并同时比较
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> s;
		TreeNode* p = root;

		//int lastval = INT_MIN; 有一个测试用例是[-2147483648]，无法通过
		//int lastval;

		//也可以只留一个current，与先前的current比较即可
		int current;
		bool isFirst = true;

		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				p = s.top();

				// inorder traversal
				if (!isFirst) {
					if (p->val <= current) {
						return false;
					}
					current = p->val;
				}
				else {
					current = p->val;
					isFirst = false;
				}

				s.pop();
				p = p->right;
			}
		}
		return true;
	}
};

//int main() {
//	/*TreeNode* root = new TreeNode(2);
//	root->left = new TreeNode(1);
//	root->right = new TreeNode(3);*/
//
//
//	/*TreeNode* root = new TreeNode(10);
//	root->left = new TreeNode(5);
//	root->right = new TreeNode(15);
//
//	TreeNode* tmp = root->right;
//	tmp->left = new TreeNode(6);
//	tmp->right = new TreeNode(20);*/
//
//	TreeNode* root = new TreeNode(INT_MIN);
//
//	bool ret = Solution().isValidBST(root);
//
//	return 0;
//}