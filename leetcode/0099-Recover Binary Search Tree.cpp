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
						//第一次找到小于前面的数，将前一结点prev赋给first
						if (!next) {
							//C4703 使用了可能未初始化的本地指针变量
							if (prev) {
								first = prev;
							}
							next = true;
						}
						//第二次找到小于前面的数，将当前结点的值赋给second
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
		//TODO 相邻交换的话 second是为空的 需要从first找到second，进行交换
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