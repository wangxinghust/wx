#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};


// https://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;

		stack<TreeNode*> s;
		TreeNode* p = root;
		unordered_map<TreeNode*, bool> visit;

		while (p || !s.empty()) {
			while (p) {
				visit[p] = true;
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				TreeNode* tmp = s.top();
				s.pop();
				if (visit[tmp]) {
					visit[tmp] = false;
					s.push(tmp);
					p = tmp->right;
				}
				else {
					ret.push_back(tmp->val);
					p = nullptr;
				}
			}
		}
		return ret;
	}
};

// 思路二
// 要保证根结点在左孩子和右孩子访问之后才能访问，
// 因此对于任一结点P，先将其入栈。
// 如果P不存在左孩子和右孩子，则可以直接访问它；
// 或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，
// 则同样可以直接访问该结点。若非上述两种情况，
// 则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，
// 左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
class Solution2 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;

		stack<TreeNode*> s;
		TreeNode* cur; // 当前节点
		TreeNode* pre = nullptr; // 前一次访问的节点
		s.push(root);
		while (!s.empty()) {
			cur = s.top();
			if ((!cur->left && !cur->right) ||
				(pre && (pre == cur->left || pre == cur->right)) // pre==左/右孩子，if pre==左孩子，那现在访问的应该是右孩子，除非右孩子不存在，if pre==右孩子，则说明左右孩子都访问过了
				) {
				ret.push_back(cur->val);
				s.pop();
				pre = cur;
			}
			else {
				// 进栈先右后左，则出栈时先左后右
				if (cur->right) {
					s.push(cur->right);
				}
				if (cur->left) {
					s.push(cur->left);
				}
			}
		}
		return ret; 
	}
};