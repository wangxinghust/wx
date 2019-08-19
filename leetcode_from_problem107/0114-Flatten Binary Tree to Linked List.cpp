#include <cstddef>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Runtime: 4 ms, faster than 93.42% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage : 9.7 MB, less than 87.50 % of C++ online submissions for Flatten Binary Tree to Linked List.
// ����˼·�����ǵ������������ұ��г�ͻ�������ȫ������ţ�����ǰ�����������һ��prevָ�룬�������һ������
// ���һ��ѭ�������������������Ƽ���
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* p = root, * prev = NULL;
		stack<TreeNode*> st;
		while (p || !st.empty()) {
			while (p) {
				// �洢�������ӣ���ǰ������Ĳ���
				prev = p;

				st.push(p);
				p = p->left; // �μǱ����ĵ������
			}
			if (!st.empty()) {
				p = st.top();
				st.pop();

				// ���Һ�������prev��������������������Ĳ���
				prev->left = p->right;

				p = p->right; // �μǱ����ĵ������
			}
		}

		// ���ѭ����������ȫ���Ƶ��ұ�
		p = root;
		while (p) {
			p->right = p->left;
			p->left = NULL;
			p = p->right;
		}
	}
};

// leetcode by jaewoo
// ��ÿ�����root��ȷ���������Ӻ��Һ��ӣ������ӵ����һ���Һ���right����root���Һ������ӵ����һ���Һ���right��
// Ȼ��ɾ��root���Һ��ӣ��ƶ�root�����ӵ��ұߣ���root������
// ÿ�����Ӧ��ֻ�ᱻ����һ�Σ������ʱ�临�Ӷ���O(n)���ռ临�Ӷ�ΪO(1)
// Runtime: 4 ms, faster than 93.42% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage : 9.5 MB, less than 100.00 % of C++ online submissions for Flatten Binary Tree to Linked List.
class Solution2 {
public:
	void flatten(TreeNode* root) {
		while (root) {
			if (root->left && root->right) {
				TreeNode* tmp = root->left;
				while (tmp->right) {
					tmp = tmp->right;
				}
				tmp->right = root->right;
			}

			if (root->left) {
				root->right = root->left;
			}

			// �������ƶ���ɾ������
			root->left = NULL;
			root = root->right;
		}
	}
};

//int main(int argc, char* argv[]) {
//	TreeNode p0(1), p1(2), p2(5), p3(3), p4(4), p5(6);
//	p0.left = &p1;
//	p0.right = &p2;
//	p1.left = &p3;
//	p1.right = &p4;
//	p2.right = &p5;
//	Solution().flatten(&p0);
//	return 0;
//}