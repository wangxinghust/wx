#include <vector>
using namespace std;
// Definition for a binary tree node.
#include <cstddef>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//leetcode by Wangxinlei, dp solution
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode*>();
		vector<TreeNode*> res(1, nullptr);
		for (int i = 1; i <= n; i++) {
			vector<TreeNode*> tmp;
			for (int j = 0; j < res.size(); j++) {
				TreeNode* oldroot = res[j];

				// 1) The nth node is the new root, so newroot->left = oldroot;
				TreeNode* root = new TreeNode(i);
				TreeNode* target = clone(oldroot);
				root->left = target;
				tmp.push_back(root);

				// 2) the nth node is not root
				if (oldroot) {
					TreeNode* tmpold = oldroot;
					// the node in the old tree has a right child
					// we can perform: old node->right = nth node, nth node ->left = right child
					while (tmpold->right) {
						// �����½��
						TreeNode* nonroot = new TreeNode(i);
						// ����ԭ����������
						TreeNode* tright = tmpold->right;
						// ԭ���rightָ���½��
						tmpold->right = nonroot;
						//�½ڵ�leftָ�򱸷ݵ������� �������
						nonroot->left = tright;

						//clone
						TreeNode* target = clone(oldroot);
						//push
						tmp.push_back(target);
						//�ָ�ԭ״̬���Ա��´�ѭ��ʹ�� �˴��ָ�����ע��
						tmpold->right = tright;
						//�ƶ�tmpold���
						tmpold = tmpold->right;
					}

					// when we reach the end of the tree, don't forget we can also add the nth node here.
					tmpold->right = new TreeNode(i);
					TreeNode* target = clone(oldroot);
					tmp.push_back(target);
					//�ָ�ԭ���״̬ ע�͵���Ӱ������res[j]��ʹ����ϣ�����ָ�ԭ״̬
					tmpold->right = nullptr;
				}
			}
			res = tmp;
		}
		return res;
	}

	TreeNode* clone(TreeNode* root) {
		if (root == nullptr) return nullptr;
		TreeNode* newRoot = new TreeNode(root->val);
		newRoot->left = clone(root->left);
		newRoot->right = clone(root->right);
		return newRoot;
	}
};

//int main(int argc, char* argv[]) {
//	vector<TreeNode*> res = Solution().generateTrees(8);
//	return 0;
//}