#include <stack>
using namespace std;

// Definition for a binary tree node
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
	void recoverTree(TreeNode* root) {
		if (!root) return;
		TreeNode* first = nullptr, * second = nullptr;

		stack<TreeNode*> s;
		TreeNode* p = root;
		TreeNode* prev = nullptr;
		int current;
		bool isFirst = true, next = false;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				p = s.top();

				if (!isFirst) {
					if (p->val <= current) {
						//��һ���ҵ�С��ǰ���������ǰһ���prev����first
						if (!next) {
							//C4703 ʹ���˿���δ��ʼ���ı���ָ�����
							if (prev) {
								first = prev;
							}
							next = true;
						}
						//�ڶ����ҵ�С��ǰ�����������ǰ����ֵ����second
						else {
							second = p;
						}
					}

				}
				else {
					prev = p;
					current = p->val;
					isFirst = false;
				}

				s.pop();
				prev = p;
				current = p->val;
				p = p->right;
			}
		}
		//TODO ���ڽ����Ļ� second��Ϊ�յ� ��Ҫ��first�ҵ�second�����н���
		if (first && second) {
			swap(first->val, second->val);
		}
	}
};

int main(int argc, char* argv[]) {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	TreeNode* tmp = root;
	tmp = tmp->right;
	tmp->left = new TreeNode(2);

	Solution().recoverTree(root);

	return 0;
}