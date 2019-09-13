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

// ˼·��
// Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ�
// ��˶�����һ���P���Ƚ�����ջ��
// ���P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
// ����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ�
// ��ͬ������ֱ�ӷ��ʸý�㡣�����������������
// ��P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ��
// �������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
class Solution2 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;

		stack<TreeNode*> s;
		TreeNode* cur; // ��ǰ�ڵ�
		TreeNode* pre = nullptr; // ǰһ�η��ʵĽڵ�
		s.push(root);
		while (!s.empty()) {
			cur = s.top();
			if ((!cur->left && !cur->right) ||
				(pre && (pre == cur->left || pre == cur->right)) // pre==��/�Һ��ӣ�if pre==���ӣ������ڷ��ʵ�Ӧ�����Һ��ӣ������Һ��Ӳ����ڣ�if pre==�Һ��ӣ���˵�����Һ��Ӷ����ʹ���
				) {
				ret.push_back(cur->val);
				s.pop();
				pre = cur;
			}
			else {
				// ��ջ���Һ������ջʱ�������
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